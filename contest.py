#!/bin/python3

import os, shutil

contest_name = input("Contest Name - ") + "/"
#contest_name = name.replace(" ", "-") + "/"

par_dir = os.getcwd();
contest_dir = os.path.join(par_dir, contest_name)

try :
	os.mkdir(contest_dir)
	# print("success")
except OSError as e:
	print(e);
	exit()

# template = par_dir + "template.cpp"
files = ('a', 'b', 'c', 'd', 'e', 'f',)
src = par_dir+"/template.cpp"

for i in files:
	dest = contest_dir + i + ".cpp"
	copied_path = shutil.copy(src, dest)
	# print("success")

# END OF FILE
