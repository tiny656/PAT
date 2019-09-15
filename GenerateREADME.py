#coding: utf-8
import sys, os, functools

# https://github.com/tiny656/PAT/blob/master/PAT%20(Advanced%20Level)%20Practise/1001_A%2BB%20Format%20(20).cpp
codeRules = [
    {
        'name': 'Top-Level',
        'folderName': 'PAT (Top Level) Practise',
        'url': '',
    },
    {
        'name': 'Advance-Level',
        'folderName': 'PAT (Advanced Level) Practise',
        'url': '',
    },
    {
        'name': 'Basic-Level',
        'folderName': u'PAT (Basic Level) Practise （中文）',
        'url': '',
    },
    {
        'name': u'中国大学MOOC-陈越、何钦铭-数据结构-起步能力自测题',
        'folderName': u'中国大学MOOC-陈越、何钦铭-数据结构-起步能力自测题',
        'url': '',
    },
    {
        'name': u'基础编程题目集',
        'folderName': u'基础编程题目集',
        'url': '',
    },
    {
        'name': u'数据结构与算法题目集（中文）',
        'folderName': u'数据结构与算法题目集（中文）',
        'url': '',
    }
]

preContent = u'''
## PAT Online Judge(https://pintia.cn/problem-sets) [![Build Status](https://img.shields.io/endpoint.svg?url=https%3A%2F%2Factions-badge.atrox.dev%2Ftiny656%2FPAT%2Fbadge%3Fref%3Dmaster&style=flat)](https://actions-badge.atrox.dev/tiny656/PAT/goto?ref=master)

:books:PAT是浙江大学计算机程序设计能力测试系统，被用于研究生机试和PAT证书资格测试

这个Project维护大部分题库的代码，其中的一些也参考过一些blog版本

代码主要语言使用`C++`, `C`, `Python`, `Java`

绝大多数代码中开头的注释写有简单的解题思路，希望对大家能有所帮助，有关研究生生活的信息，也欢迎咨询:smiley:


## 目录
- [Top-Level](#top-level)
- [Advance-Level](#advance-level)
- [Basic-Level](#basic-level)
- [中国大学MOOC-陈越、何钦铭-数据结构-起步能力自测题](#中国大学mooc-陈越何钦铭-数据结构-起步能力自测题)
- [基础编程题目集](#基础编程题目集)
- [数据结构与算法题目集(中文)](#数据结构与算法题目集中文)

'''
class CodeType:
    CPLUSPLUS = 1
    PYTHON = 2
    JAVA = 4
    C = 8

    @staticmethod
    def getCodeType(ext):
        if ext == '.cpp':
            return CodeType.CPLUSPLUS
        elif ext == '.py':
            return CodeType.PYTHON
        elif ext == '.java':
            return CodeType.JAVA
        elif ext == '.c':
            return CodeType.C

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
        for id in sorted(self.items.keys(), key = functools.cmp_to_key(self.__idCmp)):
            item = self.items[id]
            tbl += str(item) + '\n'
        return tbl
    
    def __idCmp(self, x, y):
        if '-' in x and '-' in y:
            a = x.split('-')
            b = y.split('-')
            if a[0] == b[0]:
                if a[1].isdigit() and b[1].isdigit():
                    return -1 if int(a[1]) < int(b[1]) else 1
                else:
                    return -1 if a[1] < b[1] else 1
            else:
                if a[0].isdigit() and b[0].isdigit():
                    return -1 if int(a[0]) < int(b[0]) else 1
                else:
                    return -1 if a[0] < b[0] else 1
        else:
            if x.isdigit() and y.isdigit():
                return -1 if int(x) < int(y) else 1
            else:
                return -1 if x < y else 1

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
            codeUrl += '[`Java`](%s/%s_%s.java)' % (githubUrl, self.id, self.name.replace(' ', '%20'))
        if self.code & CodeType.C:
            codeUrl += '[`C`](%s/%s_%s.c)' % (githubUrl, self.id, self.name.replace(' ', '%20'))
        ret = u'| %s | %s | %s |' % (self.id, self.name, codeUrl)
        return ret


def buildREADME():
    tables = []
    for codeRule in codeRules:
        name = codeRule.get('name')
        folderName = codeRule.get('folderName')
        baseUrl = codeRule.get('url')
        table = Table(folderName, name, baseUrl)
        for path, dirs, files in os.walk(folderName):
            for filename in files:
                id, problem = filename.split('_')
                problem, ext = os.path.splitext(problem)
                item = Item(id, problem, CodeType.getCodeType(ext), table)
                table.addItem(item)
        tables.append(table)

    with open('README.md', 'w') as f:
        f.write(preContent)
        for t in tables:
            f.write(str(t))

if __name__ == '__main__':
    buildREADME()
