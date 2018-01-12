#coding: utf-8
import sys
reload(sys)
sys.setdefaultencoding('utf8')
import os
# https://www.patest.cn/contests/pat-t-practise/
# https://www.patest.cn/contests/pat-b-practise/1001
# https://www.patest.cn/contests/pat-a-practise

# https://github.com/tiny656/PAT/blob/master/PAT%20(Advanced%20Level)%20Practise/1001_A%2BB%20Format%20(20).cpp
codeRules = [
    {
        'name': 'Top-Level',
        'folderName': 'PAT (Top Level) Practise',
        'url': 'https://www.patest.cn/contests/pat-t-practise/',
    },
    {
        'name': 'Advance-Level',
        'folderName': 'PAT (Advanced Level) Practise',
        'url': 'https://www.patest.cn/contests/pat-a-practise/',
    },
    {
        'name': 'Basic-Level',
        'folderName': u'PAT (Basic Level) Practise （中文）',
        'url': 'https://www.patest.cn/contests/pat-b-practise/',
    }
]

preContent = u'''
## PAT Online Judge(http://www.patest.cn/)

PAT是浙江大学计算机程序设计能力测试系统，被用于研究生机试和PAT证书资格测试。

这个Project维护Top Level, Advance Level和Basic Level练习题的代码，其中的一些也参考过一些blog版本。

大部分的代码使用`C++`和`Python`实现

绝大多数代码中开头的注释写有简单的解题思路，希望对大家能有所帮助，有关研究生生活的信息，也欢迎咨询^.^。


## 目录
- [Top-Level](#top-level)
- [Advance-Level](#advance-level)
- [Basic-Level](#basic-level)

'''
class CodeType:
    CPLUSPLUS = 1
    PYTHON = 2
    JAVA = 4


    @staticmethod
    def getCodeType(ext):
        if ext == '.cpp':
            return CodeType.CPLUSPLUS
        elif ext == '.py':
            return CodeType.PYTHON
        elif ext == '.java':
            return CodeType.JAVA

class Table(object):
    def __init__(self, folderName, name, url):
        self.folderName = folderName
        self.name = name
        self.url = url
        self.items = {}

    def addItem(self, item):
        if item.id not in self.items:
            self.items[item.id] = item
        else:
            self.items[item.id].code |= item.code

    def __str__(self):
        tbl = '# %s\n' % self.name
        tbl += '| ID | Title | Code |\n'
        tbl += '| :--: | :--: | :--: |\n'
        for id in sorted(self.items.iterkeys()):
            item = self.items[id]
            tbl += str(item) + '\n'
        return tbl


class Item(object):
    def __init__(self, id, name, code, table):
        self.id = id
        self.name = name
        self.code = code
        self.table = table

    def __str__(self):
        problemUrl =  self.table.url + self.id
        githubUrl = 'https://github.com/tiny656/PAT/blob/master/' + self.table.folderName.replace(' ', '%20')
        codeUrl = ''
        if self.code & CodeType.CPLUSPLUS:
            codeUrl += '[`C++`](%s/%s_%s.cpp)' % (githubUrl, self.id, self.name.replace(' ', '%20'))
        if self.code & CodeType.PYTHON:
            codeUrl += '[`Python`](%s/%s_%s.py)' % (githubUrl, self.id, self.name.replace(' ', '%20'))
        if self.code & CodeType.JAVA:
            codeUrl += '[`Java`](%s/%s_%s.java)\n' % (githubUrl, self.id, self.name.replace(' ', '%20'))
        ret = u'| %s | [%s](%s) | %s |' % (self.id, self.name, problemUrl, codeUrl)
        return ret


def build():
    tables = []
    for codeRule in codeRules:
        name = codeRule.get('name')
        folderName = codeRule.get('folderName')
        baseUrl = codeRule.get('url')
        tag = codeRule.get('tag')
        table = Table(folderName, name, baseUrl)
        for path, dirs, files in os.walk(folderName):
            for filename in files:
                id = filename[:4]
                problem, ext = os.path.splitext(filename[5:])
                item = Item(id, problem, CodeType.getCodeType(ext), table)
                table.addItem(item)
        tables.append(table)


    with open('README.md', 'w') as f:
        f.write(preContent)
        for t in tables:
            f.write(str(t))

if __name__ == '__main__':
    build()





