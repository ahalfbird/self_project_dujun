from django.http import HttpResponse
from django.shortcuts import render,redirect
from LocalModel import models
from . import forms

def main(request):
    urlstring={"runoob":"<a href='http://127.0.0.1:8000/runoob/'>点击跳转</a>",
    "base":"<a href='http://127.0.0.1:8000/base/'>点击跳转</a>",
    "subhello":"<a href='http://127.0.0.1:8000/subhello/'>点击跳转</a>",}
    return render(request, 'main.html', {"urlstring":urlstring})
    
    
def runoob(request):
    import datetime
    now  =datetime.datetime.now()
    stringssss={"title":"99"}
    bookssss={"name":"asoifh","result":"99","test":"isdbo123"}
    views_str = "<a href='http://127.0.0.1:8000/base/'>点击跳转</a>"
    return render(request, 'runoob.html', {"strtmp":stringssss,"time":now,"views_str":views_str,"bookssss":bookssss})
    
def base(request):
    import datetime
    now  =datetime.datetime.now()
    stringssss={"title":"99"}
    bookssss={"name":"asoifh","result":"99","test":"isdbo123"}
    views_str = "<a href='http://127.0.0.1:8000/base/'>点击跳转</a>"
    return render(request, 'base.html', {"strtmp":stringssss,"time":now,"views_str":views_str,"bookssss":bookssss})
    
def subhello(request):
    import datetime
    now  =datetime.datetime.now()
    return render(request, 'subhello.html', {"time":now})
    
def index(request):
    urlstring={"index":"<a href='http://127.0.0.1:8000/index/'>点击跳转</a>",
    "login":"<a href='http://127.0.0.1:8000/login/'>点击跳转</a>",
    "register":"<a href='http://127.0.0.1:8000/register/'>点击跳转</a>",
    "logout":"<a href='http://127.0.0.1:8000/logout/'>点击跳转</a>",}
    return render(request, 'login/index.html',{"urlstring":urlstring})


def login(request):
    if request.session.get('is_login', None):  # 不允许重复登录
        return redirect('/index/')
    if request.method == "POST":
        # html.form >[class DuserForm]> login_form
        login_form = forms.DuserForm(request.POST)
        message = '请检查填写的内容！'
        #is_valid http://www.manongjc.com/detail/18-tmmnuoknrylwbew.html
        if login_form.is_valid():
            
            username = login_form.cleaned_data.get('username')
            password = login_form.cleaned_data.get('password')

            try:
                #username >> models.name >-->class User
                user = models.Duser.objects.get(name=username)
            except :
                message = '用户不存在！'
                #locals() 函数会以字典类型返回当前位置的全部局部变量。
                return render(request, 'login/login.html', locals())
                
            if user.password == password:
                request.session['is_login'] = True
                request.session['user_id'] = user.id
                request.session['user_name'] = user.name
                return redirect('/index/')
            else:
                message = '密码不正确！'
                return render(request, 'login/login.html', locals())
        else:
            return render(request, 'login/login.html', locals())

    login_form = forms.DuserForm()
        
    return render(request, 'login/login.html')


def register(request):
    if request.session.get('is_login', None):
        return redirect('/index/')

    if request.method == 'POST':
        register_form = forms.RegisterForm(request.POST)
        message = "请检查填写的内容！"
        if register_form.is_valid():
            username = register_form.cleaned_data.get('username')
            password1 = register_form.cleaned_data.get('password1')
            password2 = register_form.cleaned_data.get('password2')
            email = register_form.cleaned_data.get('email')
            sex = register_form.cleaned_data.get('sex')

            if password1 != password2:
                message = '两次输入的密码不同！'
                return render(request, 'login/register.html', locals())
            else:
                same_name_user = models.Duser.objects.filter(name=username)
                if same_name_user:
                    message = '用户名已经存在'
                    return render(request, 'login/register.html', locals())
                same_email_user = models.Duser.objects.filter(email=email)
                if same_email_user:
                    message = '该邮箱已经被注册了！'
                    return render(request, 'login/register.html', locals())

                new_user = models.Duser()
                new_user.name = username
                new_user.password = password1
                new_user.email = email
                new_user.sex = sex
                new_user.save()

                return redirect('/login/')
        else:
            return render(request, 'login/register.html', locals())
    register_form = forms.RegisterForm()
    return render(request, 'login/register.html', locals())


def logout(request):
    if not request.session.get('is_login', None):
        # 如果本来就未登录，也就没有登出一说
        return redirect("/login/")
    request.session.flush()
    # 或者使用下面的方法,  单独删除
    # del request.session['is_login']
    # del request.session['user_id']
    # del request.session['user_name']
    return redirect("/login/")