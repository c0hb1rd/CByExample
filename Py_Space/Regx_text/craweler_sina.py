# -*- coding: utf-8 -*-
import re
import requests

html = open('/home/cohbird/Desktop/yuhonghong.html', 'r')
content = html.read()
html.close()

fl = re.findall('width="...px" height="...px" src="(http://ww..sinaimg.cn/cmw218/.................................jpg)">', content, re.S)
i = 1
for each in fl:
    print 'Downloading:(%d)' % (i) + each
    pic = requests.get(str(each))
    fp = open('余烘烘' + str(i) + '.jpg', 'wb')
    fp.write(pic.content)
    fp.close()
    i += 1

