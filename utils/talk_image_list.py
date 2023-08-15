from bs4 import BeautifulSoup

import sys, os, shutil

if len(sys.argv) < 2:
    print(f"Usage is {sys.argv[0]} talk_file [destination_folder]", file=sys.stderr)
    exit(1)

all_images = []
with open(sys.argv[1]) as talk_file:
    page = BeautifulSoup(talk_file, 'html.parser')
    all_images = [img.get('src') for img in page.findAll('img')]
    all_images += [video.get('data-src') for video in page.findAll('video')]
    
    for tag in page.findAll('section'):
        if tag.get('data-background-image') is not None:
            all_images.append(tag.get('data-background-image'))

base_path = os.path.abspath(os.path.dirname(sys.argv[1]))
file_paths = [os.path.join(base_path, image) for image in all_images]

if len(sys.argv) == 2:
    print(" ".join(file_paths))
else:
    dest_folder = sys.argv[2]
    if not os.path.isdir(dest_folder):
        print("Destination folder does not exist", file=sys.stderr)
        exit(0)
        
    for path in file_paths:
        dest = os.path.join(dest_folder, os.path.basename(path))
        shutil.copy2(path, dest)
        
