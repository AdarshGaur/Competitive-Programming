#!/bin/python3

import os, shutil

contest_name = input("Contest Name - ") + "/"

par_dir = os.getcwd();
new = par_dir + "/temp"
contest_dir = os.path.join(new, contest_name)

try :
	os.mkdir(contest_dir)
	# print("success")
except OSError as e:
	print(e);
	exit()

files = ('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',)
src = par_dir+"/Template.cpp"

for i in files:
	dest = contest_dir + i + ".cpp"
	copied_path = shutil.copy(src, dest)
	# print("success")

# END OF FILE
