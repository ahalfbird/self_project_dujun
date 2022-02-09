import os
import sys
import time
import subprocess

"""
gcc bmpio.o -o bmpio
gcc -c $(CFLAG) bmpio.c
"""

pypath = sys.argv[0]

compile_file = sys.argv[1]

file_name = ''

#not .c file
if not (compile_file.endswith(".c", 0, len(compile_file))):
    sys.exit(0)

file_name = compile_file[0:len(compile_file)-2]
#time.sleep(5)
print("file_name=%s compile_file=%s " %(file_name,compile_file))

if (os.path.exists(file_name + '.o')):
    os.remove(file_name + '.o')
if (os.path.exists(file_name + '.exe')): 
    os.remove(file_name + '.exe')

makecmd = ['gcc','-c', compile_file]
print("start to launch [%s] " %(makecmd))
mess_make = subprocess.Popen(makecmd, stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
print(mess_make)

time.sleep(1)
if (os.path.exists(file_name + '.o')):
    print("%s.o is already generated" %(file_name))
else:
    print("%s.o does not exist" %(file_name))

makecmd = ['gcc',file_name + '.o', '-o' ,file_name]
print("start to launch [%s] " %(makecmd))
mess_make = subprocess.Popen(makecmd, stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
print(mess_make)

time.sleep(1)
if (os.path.exists(file_name + '.exe')):
    print("%s.exe is already generated" %(file_name))
else:
    print("%s.exe does not exist" %(file_name))

time.sleep(1)
print("%s.exe will start" %(file_name))
makecmd = 'start ' + file_name + '.exe'
mess_make = os.popen(makecmd,'w',1)