import urllib.request
import os
import filecmp
import zipfile
import time
import tkinter as tk
import tkinter.messagebox as tm
import subprocess
	
def un_zip(path_zip, path_aim):
    z = zipfile.ZipFile(path_zip, 'r')
    for p in z.namelist():
        z.extract(p, path_aim)
    z.close()
def kill_exe(exe_name):
        rcmd('taskkill /f /im'+exe_name)

def rcmd(cmd):
        os.system(cmd)
        #res = subprocess.call(cmd, shell=True, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
#kill_exe("\"M Words Book-en.exe\"")
#kill_exe("\"M Words Book-zh.exe\"")
rcmd("cls")
url = 'https://mtools.makerlife.cf/mwbvertion.mts'
#print("正在检查更新")
urllib.request.urlretrieve(url, "mwbvertion.mts")
status = filecmp.cmp("mwbvertion.mts", "v.mts")
os.remove("mwbvertion.mts")
if status:
    #print("当前为最新版本，无需更新")
    #time.sleep(3)
    a=1
else:
    url = 'https://mtools.makerlife.cf/userupdate.zip'
    urllib.request.urlretrieve(url, "userupdate.zip")
    if tm.askquestion("检查更新","有新版本可用！是否安装最新版？") == "yes":
        #win32ui.MessageBox("You pressed 'Yes'")
        kill_exe("\"M Words Book.exe\"")
        rcmd("cls")
        #os.system("cls")
        un_zip("userupdate.zip",os.getcwd())
        os.remove("userupdate.zip")
        tm.showinfo("检查更新","最新版本已成功安装")
        #rcmd("\"M Words Book.exe\"")
        #os.system("start \"M Words Book.exe\"")
        #time.sleep(3)
    else:
        os.remove("userupdate.zip")
