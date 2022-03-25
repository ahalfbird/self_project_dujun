import os
from django.core.mail import send_mail
from django.core.mail import EmailMultiAlternatives

os.environ['DJANGO_SETTINGS_MODULE'] = 'HelloWorld.settings'

if __name__ == '__main__':   

#    send_mail(
#        '邮件主题',
#        '王志文吃屁',
#        'dujun@meigsmart.com',
#        ['wangzhiwen@meigsmart.com'],
#    )
    
    subject, from_email, to = '测试邮件主题', 'dujun@meigsmart.com',['wangzhiwen@meigsmart.com','lizekun@meigsmart.com']
    text_content = '测试邮件: 王志文吃屁'
    html_content = '<p>欢迎访问<a href="http://www.baidu.com" target=blank>www.baidu.com</a>，王志文吃屁！</p>'
    msg = EmailMultiAlternatives(subject, text_content, from_email, to)
    msg.attach_alternative(html_content, "text/html")
    msg.send()