import os
from pyquery import PyQuery as pq
from urllib import request as urllib2
import ast
import sys
import webbrowser
from bs4 import BeautifulSoup


def credentials( url, username, password):
    #a obj with http-user-pwd message
    p = urllib2.HTTPPasswordMgrWithDefaultRealm()
    #embody obj
    p.add_password(None, url, username, password)
    #get the body of authoritation
    handler = urllib2.HTTPBasicAuthHandler(p)
    #use the opener to fetch a url
    opener = urllib2.build_opener(handler)
    # Install the opener
    urllib2.install_opener(opener)


def alter1_url():
    '''
    get raw params
    this params must be included with a couple of '"',
    and the params must apply to wiki search grammar.
    so that i only need to replace ' ' to '+'
    '''
    
    rawdata=sys.argv[1]
    test_params="message:nfc branch:MC557"
    
    test_params=test_params.replace(' ','+')
    
    #print(test_params)
    
    return test_params

#set the must val
searchuser='dujun'
searchpwd='123456'
searchhost='192.168.0.240'

#deal with input search params
finishparams=''
finishparams= alter1_url()

#deal with url and authorization
searchurl='http://'+searchhost+'/q/'+finishparams
credentials(searchurl, searchuser, searchpwd)
#print(searchurl)

#http://192.168.0.240/q/message:+nfc+AND+MC582+branch:MC565X_R
#webbrowser.open(searchurl)

url_body = urllib2.urlopen("http://192.168.0.138/wiki/index.php/%E7%9F%A5%E8%AF%86%E5%BA%93")
url_html=url_body.read()
soup = BeautifulSoup(url_html,"lxml")
#print('\nsoup:\n',soup.prettify())
#doc = pq(url_html)
#print('\ndoc:\n'+str(doc))

print(soup.body)




    


