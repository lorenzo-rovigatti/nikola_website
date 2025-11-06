<!--
.. title: Building a Python Package with CMake, pybind11, and scikit-build-core
.. slug: pybind_cmake
.. date: 2025-11-05 17:00:48 UTC+02:00
.. tags: pybind, cmake, scikit-core, python, C++
.. category: development
.. link: 
.. description: 
.. type: text
-->

```{contents} Table of Contents
:depth: 2
:backlinks: none
```

# Building a Python Package with CMake, pybind11, and scikit-build-core

I'm the main developer and maintainer of [oxDNA](https://github.com/lorenzo-rovigatti/oxDNA/), a simulation engine implementing oxDNA and oxRNA, two of the most widely-used coarse-grained models used in nucleic-acid nanotechnology. The software has been used in [hundreds of publications](https://dna.physics.ox.ac.uk/index.php?title=Publications), and it is part of a larger ecosystem (see *e.g.* [the oxDNA.org webserver](https://oxdna.org/), or [oxview](https://sulcgroup.github.io/oxdna-viewer/), a browser-based editing/visualising tool).

A few years ago I started working making some of oxDNA's features available to Python through [pybind11](https://github.com/pybind/pybind11). As a result, recent oxDNA versions can optionally compile and install an `oxpy` module (which, for instance, can be used to [streamline analysis](https://lorenzo-rovigatti.github.io/oxDNA/oat/index.html) of simulation results, or run [metadynamics](https://github.com/lorenzo-rovigatti/oxDNA/tree/master/examples/METADYNAMICS) simulations). For practical reasons, it is possible to install `oxpy` in two ways: 

1. By using pip:
```
pip install . # from the root folder
```
2. By using the usual CMake pipeline
```
mkdir build
cd build
cmake .. -DPython=On # you can add more options, such as -DCUDA=On
make install
```

The requirement of having two ways of compiling the code forced me to conjure up, mostly by trial and error, a rather obscure compilation process. Unfortunately (but perhaps not unsurprisingly), it turns out that it procedure was not only obscure, but also fragile, as [upgrading pip broke it](https://github.com/lorenzo-rovigatti/oxDNA/issues/179). I then spent a weekend trying to fix things up. This post is the result of this effort, and I decided to write mostly to help my future self. Throughout the post I'll be using PIP and CMAKE to refer to the two installation methods introduced before, respectively.

Here I will explain how to create a Python package that includes a C++ extension built with CMake and pybind11, and how to package it cleanly using [scikit-build-core](https://github.com/scikit-build/scikit-build-core) so that it fulfills my (oxDNA's?) needs.

A tar file containing a full example (*e.g.* all the files described in this post) can be downloaded <a href="/oxpy_mwe.tgz">here</a>. The example combines:

- CMake for building the C++ extension
- pybind11 for Python bindings
- scikit-build-core for packaging
- setuptools_scm for automatic versioning from git tags/commits

## Project layout

```
oxpy-mwe/
├─ CMakeLists.txt
├─ example.py
├─ pyproject.toml
├─ README.md
└─ src/
   └─ oxpy_mwe/
      ├─ __init__.py
      ├─ core.cpp
      └─ pyproject_cmake.toml
```

## Module source files

The `src/oxpy_mwe/core.cpp` file uses pybind11 to create one module that exposes a simple function:

```c++
#include <pybind11/pybind11.h>

namespace py = pybind11;

int add(int a, int b) { return a + b; }

PYBIND11_MODULE(core, m) {
    m.doc() = "oxpy_mwe core module";
    m.def("add", &add, "Add two integers");
}
```

Then we create an `__init__.py` file that imports the `add` function from the core module and handles the module version by importing a `_version.py` that will be generated at compile time:

```python
from .core import add

try:
    from ._version import version as __version__
except Exception:
    __version__ = "0.0.0"
```

## CMakeLists.txt

Here I split the file in a few sections, so that they can be commented separately.

```cmake
cmake_minimum_required(VERSION 3.18)
project(oxpy_mwe LANGUAGES CXX)

find_package(Python COMPONENTS Interpreter Development.Module REQUIRED)
find_package(pybind11 CONFIG QUIET)
if(NOT pybind11_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11.git
    GIT_TAG v2.12.0
  )
  FetchContent_MakeAvailable(pybind11)
endif()
```

We look for python and pybind11 (which is fetched from the internet if not found on the system).

```cmake
# Create a staging directory for the Python package
set(OXPY_BASE_DIR "${CMAKE_BINARY_DIR}/python")
set(OXPY_PACKAGE_DIR "${OXPY_BASE_DIR}/oxpy_mwe")
# Make sure the directory exists
file(MAKE_DIRECTORY ${OXPY_PACKAGE_DIR})
```

We create a `python/oxpy_mwe` folder relative to the building directory where all the package files will be stored.

```cmake
pybind11_add_module(core MODULE src/oxpy_mwe/core.cpp)

# Place the compiled extension (.so) in that folder
set_target_properties(core
  PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${OXPY_PACKAGE_DIR}"
    SUFFIX ".so"
)
```

We tell CMake to compile the module, make it a shared `.so` object and put it in the output folder (*i.e.* `python/oxpy_mwe`).

```cmake
configure_file(src/oxpy_mwe/__init__.py ${OXPY_PACKAGE_DIR}/__init__.py COPYONLY)
```

We copy `__init__.py` to the output folder.

```cmake
if(SKBUILD)
  # copy the _version.py file generated by setuptools_scm
  configure_file(${CMAKE_SOURCE_DIR}/src/oxpy_mwe/_version.py ${OXPY_PACKAGE_DIR}/_version.py COPYONLY)
  # install the package to a location where scikit-build can find it
  install(DIRECTORY ${OXPY_PACKAGE_DIR}/ DESTINATION oxpy_mwe)
else()
  configure_file(${CMAKE_SOURCE_DIR}/README.md ${OXPY_PACKAGE_DIR}/README.md COPYONLY)
  configure_file(${CMAKE_SOURCE_DIR}/src/oxpy_mwe/pyproject_cmake.toml ${OXPY_BASE_DIR}/pyproject.toml)
  # Install the package using pip
  option(OXPY_SYSTEM_INSTALL "Install system-wide via pip" OFF)
  if(OXPY_SYSTEM_INSTALL)
    install(CODE "execute_process(COMMAND ${Python_EXECUTABLE} -m pip install ${OXPY_BASE_DIR})")
  else()
    install(CODE "execute_process(COMMAND ${Python_EXECUTABLE} -m pip install --user ${OXPY_BASE_DIR})")
  endif()
endif()
```

Here the compilation proceeds differently for PIP and CMAKE: in the former case pip uses scikit-build-core, which defines a CMake variable SKBUILD that is used to determine what to do:

* In the case of PIP, the `_version.py` file, generated by `setuptools_scm`, see below, is copied from the `/src/oxpy_mwe/` folder to the output folder. Then, when the `install` step is invoked, the the output folder is copied as-is to the target folder, which in this case is again a local folder (`oxpy_mwe`). There, if the correct path is given in the `wheel.packages` option of `pyproject.toml`, scikit-build-core will be able to find the package and use it to copy it to the correct Python's `site-packages` folder.
* For the CMAKE method, we copy the README and the correct `pyproject.toml` (the one stored in the `src/oxpy_mwe` folder) to the target folder, and then install the package directly with `pip`.

The key point here is that we use slightly different `pyproject.toml` files for the PIP and CMAKE methods, as described below.

## pyproject.toml

The `pyproject.toml` file for the PIP method is as follows:

```toml
[build-system]
requires = ["scikit-build-core>=0.9", "setuptools_scm>=8", "pybind11>=2.10"]
build-backend = "scikit_build_core.build"

[project]
name = "oxpy_mwe"
dynamic = ["version"]

[...]

[tool.scikit-build]
metadata.version.provider = "scikit_build_core.metadata.setuptools_scm"
wheel.packages = ["oxpy_mwe"]

[tool.setuptools_scm]
version_file = "src/oxpy_mwe/_version.py"
fallback_version = "unknown"
local_scheme = "no-local-version"
```

Here I'm omitting standard project-related fields (such as `classifiers`, `authors`, *etc*). Here we use `scikit-build-core` as the build backend, and tell it to look for the package in the `oxpy_mwe` folder. If this is not specified, omitted or if the path is wrong, `scikit-build-core` will be happy to consider `src/oxpy_mwe` as the package folder, and silently copy that to the `site-packages` folder. I believe that this happens because there is a `src/oxpy_mwe/__init__.py` file, and that, according to `scikit-build-core`, makes the folder a Python package.

The last lines tell `setuptools_scm` to write a version file that will be copied to the output folder by CMake. The `local_scheme = "no-local-version"` makes sure that no dates or times are appended to the version string, which would, very confusingly, generate mismatches when installing the package with pip.

For CMAKE, the `pyproject.toml` file is copied to the right folder at runtime by CMake starting from the following `/src/oxpy_mwe/pyproject_cmake.toml` file:

```toml
[build-system]
requires = ["scikit-build-core>=0.9", "setuptools_scm>=8"]
build-backend = "setuptools.build_meta"

[...]

[tool.setuptools.package-data]
oxpy_mwe = ["*.so"]

[tool.setuptools_scm]
version_file = "oxpy_mwe/_version.py"
fallback_version = "0.0.0"
local_scheme = "no-local-version"
root = "${CMAKE_SOURCE_DIR}"
```

Again, I omit the project metadata in order to focus on the important content. Here we use `setuptools.build_meta` as the build backend, and tell it that the compiled extension (`*.so`) is part of the package. Then, we again use `setuptools_scm` to write a version file, but in this case we have to point it to the right root folder, where it can find the SCM (*i.e.* `git`) metadata. We do this with the option `root`, which is populated by CMake when it copies the file to the output folder. Note that in this case the version file is put directly into the output folder (since the `pip install .` command is invoked from the `/build/python`, where CMake has put the `pyproject.toml` file).

## Continuous integration

As a last note, when using GitHub Actions, make sure the workflow checks out the full repository with all tags so that `setuptools_scm` can detect the correct version:

```
- uses: actions/checkout@v4
  with:
    fetch-depth: 0
    fetch-tags: true
```
