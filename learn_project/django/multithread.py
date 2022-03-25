import os
import time
import pyautogui
import numpy as np
import matplotlib.pyplot as plt
import re
import sys
import random
import threading



opemap=[]
"""
0 --> not ope
1 --> ope
2 --> finish
"""
global opemapp
opemapp=0
def prtMap():
    timemax=100
    while(timemax>0):
        time.sleep(0.1)
        print(opemap)
        timemax-=1
    

def calStep(list,len):
    global opemapp
    while(opemapp<15):
        opeposition=opemap.index(0)
        opemapp=opeposition
        opemap[opeposition]=1
        time.sleep(0.2)
        list[opeposition]=list[opeposition]**2
        time.sleep(0.2)
        opemap[opeposition]=2
        print('finish do in ',threading.currentThread().getName(),'opemapp is ',opemapp)
    return opemapp
    

def testStep(args1,args2):
    print(threading.currentThread().getName(),args1,args2)
    return 0



def calMatrix(list,len):
    sidelen=len**0.5
    for i in range(len):
        list.append(random.randint(0,100))
        opemap.append(0)


list = []
calMatrix(list,16)
print(list,'\n',opemap)
print('\n\n')

threads=[]
#t=threading.Thread(target=prtMap)
#threads.append(t)
#t.start()
#t.join()
for i in range(4):
    t=threading.Thread(target=calStep,name='thread'+str(i),args=(list,16))
    threads.append(t)
    t.start()
    #t.join()
    
time.sleep(2)
print('\n\n')
print(list,'\n',opemap)
