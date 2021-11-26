#!/bin/python3

import os, shutil

name = input("Problem Name - ")
problem_name = name.replace(" ", "-") + ".cpp"

par_dir = os.getcwd();
src = par_dir + "/template.cpp"
par_dir += "/practice-problems"
problem_dir = os.path.join(par_dir, problem_name)
dest = problem_dir

try:
	copied_path = shutil.copy(src, dest);
	# print("success")
except IOError as e:
	print("Error: ", e)
	print("Try with some addons :/")

# END OF FILE