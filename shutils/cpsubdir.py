import os
import shutil

os.chdir('test')
shutil.rmtree("target") 
def searchfile(path):
    for item in os.listdir(path):
        if os.path.isdir(os.path.join(path,item)):
            searchfile(os.path.join(path, item))
        else:
            if '.png' in item:
                print(item,path)


sourcefile=''
targetfile=''

if not os.path.exists('target'):
    os.mkdir('target')


for sub in os.listdir('.'):
    if(sub=='target'):
        continue
    sourcefile=sub+'/__sprite/1.png'
    targetfile='target/'+sub+'-1.png'
    print(sub,sourcefile,targetfile)
    shutil.copy(sourcefile,targetfile)
os.chdir('..')

print('target file has:\n')
for sub in os.listdir('test/target'):
    print(sub)
