import os
import time
import pyautogui
time.sleep(0.1)
print(os.pwd())

#get size of screen
print(pyautogui.size())

#get current position of mouse
print(pyautogui.position())

px1=1920/2
py1=1080/2

pyautogui.moveTo(px1,py1,0.1)
pyautogui.click()
pyautogui.rightClick()

px1=-1920/4
py1=1080/4
pyautogui.moveRel(px1,py1,1)
pyautogui.middleClick()
pyautogui.doubleClick()
pyautogui.rightClick()

pyautogui.mouseDown()
pyautogui.moveTo(px1,py1,1)
pyautogui.dragTo(px1+px1,py1+py1,1)
pyautogui.mouseUp()

pyautogui.mouseDown()
pyautogui.moveTo(px1,py1,1)
pyautogui.dragRel(px1,py1,1)
pyautogui.mouseUp()

pyautogui.scroll(-6)
time.sleep(1)
pyautogui.scroll(6)

pyautogui.typewrite(['a','b','c'])
pyautogui.press('winleft')
pyautogui.keyDown('winleft')
pyautogui.keyUp('winleft')

#快捷键
pyautogui.hotKey('ctrl','c')

"""
键盘键字符串                        含义
'a','b','c','A','C','1','2','3',    单个字符的键
'!','@','#'等

'enter'                             回车

‘esc'                              ESC键

'shiftleft','shiftright'            左右Shift键

'altleft','altright'                左右Alt键

'ctrlleft','ctrlright'              左右Ctrl键

‘tab'(or '\t')                     Tab键

'backspace','delete'                Backspace键和Delete键

'pageup','pagedown'                 Page Up 和Page Down键

'home','end'                        Home键和End键

'up','down','left','right'          上下左右箭头键

'f1','f2','f3'等                    F1至F12键

'volumemute','volumeup',volumedown' 静音，放大音量和减小音量键

'pause'                             暂停键

'capslock','numlock','scrolllock'   Caps Lock，Num Lock和 Scroll Lock键

'insert'                            Insert键

'printscreen'                       Prtsc或Print Screen键

'winleft','winright'                左右Win键(在windows上)

'command'                           Command键(在OS X上)

'option'                            Option键(在OS X上)

"""


#确认框
pyautogui.alert('alert.')

pyautogui.confirm('If you confirm that you will continue, press OK.')

print(pyautogui.prompt('this gets string from user.'))


#get the position with png
print(pyautogui.locateOnScreen('chrome.png'))