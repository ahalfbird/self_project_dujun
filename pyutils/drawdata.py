import os
import time
import pyautogui
import numpy as np
import matplotlib.pyplot as plt
import re
import sys
list1=()
list2=()
counter=0

def findsubstringposition(str,substr,index=0):
    positionlist=()
    tmpp=0
    if(index==0):
        tmpp=str.find(substr, 0, len(str))
        positionlist+=(tmpp,)
    else:
        for i in range(0,index):
            tmpp=str.find(substr, tmpp, len(str))
            if(tmpp==-1):
                break
            positionlist+=(tmpp,)
            i+=1
            #print(positionlist)

    return positionlist
    



def getDataFromList(list,func=0,args1=0,args2=0):
    if(func==0):
        left=int(args1)
        right=int(args2)
        #func1:from position
        return int(list[left:right])
    elif(func==1):
        #func2:from left string, read number
        left=list.find(args1)
        if(left==-1):
            return -1
        else:
            left+=len(args1)
            right=re.findall(r'\d+',list[left:])
            #print(left,right)
        return int(right[0])
    elif(func==2):
        #func3:from left string and right string
        left=findsubstringposition(list,str(args1))
        right=findsubstringposition(list,str(args2))
        #print(left[0],right[0])
        if(left[0]==-1 or right[0]==-1):
            return -1
        else:
            return int(list[left[0]+len(args1):right[0]])


filename=sys.argv[1]
file=open(filename, 'r')
listf = file.readlines()
for singleline in listf:
    tmpnum=getDataFromList(singleline,2,'keypoints Run Time:','(ms)')
    #print(tmpnum)
    if(tmpnum==-1):
        continue
    counter+=1
    list1+=(int(counter),)
    list2+=(int(tmpnum),)
file.close()

plt.scatter(list1,list2)
plt.show()





