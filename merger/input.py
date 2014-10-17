import os 
import sys
import tarfile


"""these function are used by merger.py in order to manage inputs
Those inputs can be either folders or gunzipped files"""

def extract_archive(archive_path, extraction_path): 
    with tarfile.open(archive_path, 'r') as tar :
        tar.extractall(extraction_path)


def list_directory(path): 
    return  sorted([ os.path.join(path, f) for f in os.listdir(path) if os.path.isfile(os.path.join(path,f)) ])

def main () :
    if len(sys.argv) < 3:
        print """this script can be used by itsefl to extract all archive 
        in sys.argv[1] and put the results in sys.argv[2]"""
        return 0
    path = sys.argv[1]
    archives = list_directory(path)
    for archive in archives :
        extract_archive(archive, sys.argv[2])
    return 0

if __name__ == '__main__':
    main()