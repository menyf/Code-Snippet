##################################
# Created by MenYifan on 2016-10-18 
# 说明：
# 1. 请使用python3执行，如没有相关包请自行安装
# 2. 本程序只能抓取ac代码，如需抓WA/CE/TLE等代码请自行修改getList函数的url中的status参数
# 3. 在OS X 10.11.6 python3.5.2环境下测试通过
#
# Updated Version 1.1 on 2016-10-19 
# 修正了只能抓取前500条ac记录的bug，现在已经可以把所有代码抓下来了
# 
##################################
from urllib import request, parse
from io import BytesIO
from datetime import datetime
import re,html,urllib,gzip,json,os

def Login(VjudgeID, VjudgePWD):
	print('Login to vjudge.net...')
	login_data = parse.urlencode([
		('username', VjudgeID),
		('password', VjudgePWD)
	])
	req = request.Request(
		url='http://vjudge.net/user/login',
		data=login_data.encode('utf-8')
	)
	req.add_header('Host','vjudge.net')
	req.add_header('Accept', '*/*')
	req.add_header('X-Requested-With','XMLHttpRequest')
	req.add_header('Accept-Encoding','gzip, deflate')
	req.add_header('Accept-Language','zh-cn')
	req.add_header('Content-Type', 'application/x-www-form-urlencoded; charset=UTF-8')
	req.add_header('Origin', 'http://vjudge.net')
	req.add_header('Content-Length', '38')
	req.add_header('Connection', 'keep-alive')
	req.add_header('User-Agent','Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_6) AppleWebKit/602.1.50 (KHTML, like Gecko) Version/10.0 Safari/602.1.50')
	
	res = request.urlopen(req)	
	return res.getheaders()[5][1][0:43]
	if "success" in res.read().decode('utf-8'):
		print("Login successfully")
		return res.getheaders()[5][1][0:43] 
	else:
		print("wrong password or ID")
		return
	
def getList(VjudgeID, _Cookie, path, name):
	pre = -1
	now = 99999999
	cnt = 0
	tot = 0
	while not pre == now:
		pre = now
		url = "http://vjudge.net/user/submissions?username="+VjudgeID+"&status=AC&pageSize=20&maxId="+str(now)
		req = request.Request(url)
		req.add_header('Host','vjudge.net')
		req.add_header('Accept', 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8')
		req.add_header('Upgrade-Insecure-Requests','1')
		req.add_header('Cookie', _Cookie)
		req.add_header('User-Agent','Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_6) AppleWebKit/602.1.50 (KHTML, like Gecko) Version/10.0 Safari/602.1.50')
		req.add_header('Accept-Language','zh-cn')
		req.add_header('Cache-Control','max-age=0')
		req.add_header('Accept-Encoding','gzip, deflate')
		req.add_header('Connection', 'keep-alive')
		with request.urlopen(req) as f:
			data = json.loads(f.read().decode('utf-8'))
#			print(data)
			for k in data["data"]:
				tot += 1
				cnt = cnt + getCode(path,k, _Cookie, name)
				now = k[0]
				
	print("======\nDone.\nYou ACed",cnt,"problems on Vjudge,\nand you have",tot,"accepted submissions.\n")
def getCode(path, info, _cookie, name):
	VJheaders = {
		'Host': 'vjudge.net',
		'Cookie': _cookie,
		'Connection': 'keep-alive',
		'Upgrade-Insecure-Requests': '1',	
		'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
		'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_6) AppleWebKit/602.1.50 (KHTML, like Gecko) Version/10.0 Safari/602.1.50',
		'Accept-Encoding': 'gzip, deflate',
		'Accept-Language': 'zh-cn'
	}
	req = request.Request(
		url='http://vjudge.net/problem/source/'+str(info[0]),
		headers=VJheaders
	)

	res = request.urlopen(req)
	buf = BytesIO(res.read())
	gzip_f = gzip.GzipFile(fileobj=buf)
	content = gzip_f.read()	
	ttmp = content.replace(b'\xa9', b' ')
	txt = html.unescape(ttmp.decode('utf-8'))
	pattern = re.compile('Courier New,Courier,monospace">(.+?)</pre>',re.S)
	ans = pattern.findall(txt)[0]
	
	filepath = path + '%s%s.%s' %(info[2],info[3],info[7].lower())
	if(os.path.isfile(filepath)):
		print(info[2]+info[3]+" already exists, skip")
		return 0
	print ('Saving '+info[2]+info[3]+'.'+info[7].lower()+' to'+str(filepath))
	f = open(filepath, 'w')
	f.write("// Wrote by "+name+" on "+str(datetime.fromtimestamp(info[9]/1000))+"\n// Exe.Time "+str(info[5])+"ms Exe.Memory "+str(info[6])+"K\n")
	f.write(ans)
	f.close();
	return 1

if __name__ == "__main__":  
	print("Please make sure your ID and PASSWORD are CORRECT\nCause MYF is too lazy to take actions to unsuccessful login.")
	print("This script will download all your accepted submissions.\n")
	print("Hail Hydra, Hail ACMer. \n-- CUGBACM MenYifan")
	print("============================================")
	VjudgeID = input("Vjudge ID: ")
	VjudgePWD = input("Vjudge Password: ") 
	path = input('Path to save : ')
	name = input("Your name is : ")  # Wrote by __yourname__ on 2016-10-17 20:37:16
	cookie = Login(VjudgeID, VjudgePWD)
	getList(VjudgeID, cookie, path, name)