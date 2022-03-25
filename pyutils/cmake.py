import os
import sys
import time
import subprocess

'''
input: 

tuple with *.c
target filename [shell]*.so *.a * [win]*.dll *.lib *.exe

output:
this file will generate a file what you expect.

'''

#number of params
params_num=len(sys.argv)
#name of python script
this_file_name=sys.argv[0]
#params
params_list=[]
source_file=[]
ciri=0
for fn in sys.argv:
    params_list=params_list+[fn]
    if ciri==0 or ciri==params_num-1:
        pass
    else:
        source_file=source_file+[fn]
    ciri=ciri+1

#target file name
target_file_name=sys.argv[params_num-1]
#operation sytem
platform_os=""
make_command=""

CFLAGS=' -Wall -Wextra '
'''
-Werror                 most strict
-Wfatal-errors          stop with first error
-Wall                   open all warning
-Wextra                 open warning what '-Wall' does not include
'''

if (os.path.exists(target_file_name)): 
    os.remove(target_file_name)

if target_file_name.split(".")[-1] == "so":
    platform_os="linux"
    # gcc test_a.c test_b.c test_c.c -fPIC -shared -o libtest.so
    make_command=['gcc',CFLAGS,'-fPIC','-shared']+source_file+['-o',target_file_name]
    #print(make_command)
    mess_make = subprocess.Popen(make_command, stdout=subprocess.PIPE,stderr=subprocess.STDOUT)

    
elif target_file_name.split(".")[-1] == "a":
    platform_os="linux"
    if (os.path.exists('*.o')): 
        os.remove('*.o')
    # gcc -c test_a.c test_b.c test_c.c
    make_command=['gcc',CFLAGS,'-c']+source_file
    #print(make_command)
    mess_make = subprocess.Popen(make_command, stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
    #ar -rc libxxx.a xxx1.o xxx2.o xxx3.o
    make_command=['ar',CFLAGS,'-rc','lib'+target_file_name,'*.o']
    #print(make_command)
    mess_make =mess_make+subprocess.Popen(make_command, stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
    
    
elif target_file_name.split(".")[-1] == "dll":
    platform_os="win"
    #gcc dlltest.c -shared -o dlltest.dll -Wl,--out-implib,dlltest.lib
    make_command=['gcc',CFLAGS]+source_file+['-shared','-o',target_file_name]+['-Wl,--out-implib,dlltest.lib']
    #print(make_command)
    mess_make = subprocess.Popen(make_command, stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
    
elif target_file_name.split(".")[-1] == "lib":
    platform_os="win"
    if (os.path.exists('*.o')): 
        os.remove('*.o')
    # gcc -c test_a.c test_b.c test_c.c
    make_command=['gcc',CFLAGS,'-c']+source_file
    #print(make_command)
    mess_make = subprocess.Popen(make_command, stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
    #ar -rc libxxx.a xxx1.o xxx2.o xxx3.o
    make_command=['ar',CFLAGS,'-rc','lib'+target_file_name,'*.o']
    #print(make_command)
    mess_make =mess_make+subprocess.Popen(make_command, stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
    

elif target_file_name.split(".")[-1] == "exe":
    platform_os="win"
    make_command=['gcc',CFLAGS]+source_file+['-o',target_file_name]
    #print(make_command)
    mess_make = subprocess.Popen(make_command, stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
    
else:
    platform_os="linux"
    #gcc main.c hello.c -o main
    make_command=['gcc',CFLAGS]+source_file+['-o',target_file_name]
    #print(make_command)
    mess_make = subprocess.Popen(make_command, stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
    
print(mess_make)