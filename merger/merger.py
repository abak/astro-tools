#!/usr/bin/env python

import numpy as np
import cv2

from os.path import join
import argparse

"""this scripts is here only to merge all the hi resolution images 
contained in one folder of the DSS survey into one big, resulting image.
This should be ported to a more efficient language"""


def merge_files(files, resize):
  temp = np.zeros((64*300, 64*300, 3), dtype=np.uint8)
  current_i = 0
  current_j = 0
  for file in files :
    coord =  file.split('_')
    x = 300*int(coord[-3])
    y = 19200 - 300*(int(coord[-2])+1)
    current = cv2.imread(file)

    temp[y:y+300, x:x+300, :] = current

  if resize :
    res = cv2.resize(temp, dsize=(1920, 1920))
    return res
  else :
    return temp


if __name__ == '__main__':
  parser = argparse.ArgumentParser(description="Python version of the merger. Merges all the image in a folder into one resulting big image")
  parser.add_argument("-i", "--input", help="path to the input folder", required=True)
  parser.add_argument("-o", "--output", help="path to the output image", required=True)
  parser.add_argument("-r", "--resize", action="store_true", help="if set, will resize the output image down to 1920x1920")
  args = parser.parse_args()

  file_list = open_input(args.input)

  result = merge_files(file_list, args.resize)
  cv2.imwrite(join(path, args.output), result)
