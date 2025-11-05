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

This post explains how to create a Python package that includes a C++ extension built with CMake and pybind11, and how to package it cleanly using scikit-build-core. The goal is to produce a wheel that contains the compiled extension and the processed Python sources, not the raw `src/` tree.

## Overview

This example combines:

- CMake for building the C++ extension  
- pybind11 for Python bindings  
- scikit-build-core for packaging  
- setuptools_scm for automatic versioning from git tags

## Project layout

```
oxpy-mwe/
├─ CMakeLists.txt
├─ pyproject.toml
├─ README.md
└─ src/
   └─ oxpy_mwe/
      ├─ __init__.py
      └─ core.cpp
```

A tar file can be downloaded ???

## pyproject.toml

(Insert the contents of `pyproject.toml` here)

Key points:

- `scikit-build-core` is the build backend  
- `setuptools_scm` writes a version file under `src/oxpy`  
- `wheel.install-dir` ensures packaging uses the CMake install tree

## CMakeLists.txt

(Insert the contents of `CMakeLists.txt` here)

Key points:

- A `pybind11_add_module` target builds the extension  
- Python files are staged into `${CMAKE_BINARY_DIR}/python/oxpy`  
- Use `install(TARGETS … DESTINATION oxpy)` and `install(DIRECTORY … DESTINATION oxpy)`  
- Guard convenience `pip install` steps with `if(NOT SKBUILD)`

## C++ source file (src/oxpy/core.cpp)

(Insert a minimal pybind11 example here, e.g. a function `add(a, b)` that returns `a + b`)

## Python initialization file (src/oxpy/__init__.py)

(Insert the minimal `__init__.py` that imports from ._core and defines `__version__`)

## Building and installing

To build and install the package:

1. Install build tools  
   ```
   pip install -U build scikit-build-core pybind11 setuptools_scm
   ```

2. Build the wheel  
   ```
   python -m build
   ```

3. Install the wheel  
   ```
   pip install dist/*.whl
   ```

Alternatively, install directly without creating a wheel:  
```
pip install .
```

## Verifying the installation

In Python:

```
import oxpy
print(oxpy.add(2, 3))
```

Expected output:

```
5
```

## Initializing a git repository and tagging versions

The version number is managed automatically by `setuptools_scm` based on git tags.

Run the following commands:

```
cd oxpy-mwe
git init
git add .
git commit -m "Initial commit"
git tag -a v0.1.0 -m "Version 0.1.0"
```

Then build and verify:

```
python -m build
pip install dist/*.whl
python -c "import oxpy; print(oxpy.__version__)"
```

Expected version output:

```
0.1.0
```

## Continuous integration

When using GitHub Actions, make sure the workflow checks out the full repository with all tags so that `setuptools_scm` can detect the correct version:

```
- uses: actions/checkout@v4
  with:
    fetch-depth: 0
    fetch-tags: true

- run: pip install --no-build-isolation .
```

## Notes and common issues

1. **Duplicate folders such as `python/python/oxpy`**  
   This happens if both CMake and scikit-build-core add a “python” prefix. Keep only one.

2. **Wheel includes `src/oxpy` instead of built files**  
   Use `install(DIRECTORY ... DESTINATION oxpy)` in CMake and `wheel.install-dir = "python"` in pyproject.toml.

3. **Version mismatch in CI**  
   Set `local_scheme = "node-and-date"` in the `[tool.setuptools_scm]` section of pyproject.toml and fetch full git history.

4. **Conditional pip installation**  
   Use `if(NOT SKBUILD)` in CMake to avoid recursive pip installs during wheel builds.

## Conclusion

This minimal working example provides a reproducible reference for creating mixed C++/Python packages with pybind11 and scikit-build-core.  
It handles building, packaging, and versioning cleanly and integrates smoothly with pip and continuous integration systems.
