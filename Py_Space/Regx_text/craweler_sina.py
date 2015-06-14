# -*- coding: utf-8 -*-
import re
import requests

# 由于sina http头我还没搞清，是直接源码到本地分的
html = open('/home/cohbird/Desktop/yuhonghong.html', 'r')
content = html.read()
html.close()

fl = re.findall('width="...px" height="...px" src="(http://ww..sinaimg.cn/cmw218/.................................jpg)">', content, re.S)
i = 1;
for each in fl:
    print 'Downloading:(%d)' % (i) + each
    pic = requests.get(str(each))
    fp = open('余烘烘' + str(i) + '.jpg', 'wb')
    fp.write(pic.content)
    fp.close()
    i += 1
