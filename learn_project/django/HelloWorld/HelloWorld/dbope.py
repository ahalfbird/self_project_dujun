# -*- coding: utf-8 -*-
 
from django.http import HttpResponse
 
from LocalModel.models import Duser
 
# 数据库操作
def dbadd(request):
    test1 = Duser(name='runoob')
    test1.save()
    return HttpResponse("<p>数据添加成功！</p>")

def dbgetAll(request):
    list = Duser.objects.all()
    return list
    
