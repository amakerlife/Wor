import urllib.request
import os
import filecmp
import zipfile
import time
def un_zip(path_zip, path_aim):
    z = zipfile.ZipFile(path_zip, 'r')
    for p in z.namelist():
        z.extract(p, path_aim)
    z.close()
def kill_exe(exe_name):
    os.system('taskkill /f /t /im '+exe_name)
kill_exe("\"M Words Book-en.exe\"")
kill_exe("\"M Words Book-zh.exe\"")
os.system("cls")
url = 'https://mtools.makerlife.cf/mwbvertion.mts'  
print("正在检查更新")
urllib.request.urlretrieve(url, "mwbvertion.mts")
status = filecmp.cmp("mwbvertion.mts", "v.mts")
os.remove("mwbvertion.mts")
if status:
    print("当前为最新版本，无需更新")
    time.sleep(3)
else:
    print("有新版本可用，正在下载更新")
    url = 'https://mtools.makerlife.cf/userupdate.zip'
    urllib.request.urlretrieve(url, "userupdate.zip")
    un_zip("userupdate.zip",os.getcwd())
    os.remove("userupdate.zip")
    print("最新版本已成功安装")
    time.sleep(3)
