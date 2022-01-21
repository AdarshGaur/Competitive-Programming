#!/bin/python3

import os, shutil

problem_name = input("Problem Name - ") + ".cpp"

par_dir = os.getcwd();
src = par_dir + "/Template.cpp"
par_dir += "/temp"
dest = os.path.join(par_dir, problem_name)

try:
	copied_path = shutil.copy(src, dest);
	# print("success")
except IOError as e:
	print("Error: ", e)
	print("Try with some addons :/")

# END OF FILE
