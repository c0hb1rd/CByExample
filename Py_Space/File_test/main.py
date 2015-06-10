filename = raw_input('Enter the source file name: ')
out_file = open(filename, "w+")
buf = ['#include <stdio.h>\n\n', 'int main(void)\n',\
	  '{\n','    puts("This is a test.");\n\n','    return 0;\n','}\n']

for x in buf:
	out_file.write(x)

out_file.close()

import os

exefilename = raw_input('enter the executable file name: ')
cmd = 'gcc ' + filename + ' -o ' + exefilename 
os.system(cmd)
