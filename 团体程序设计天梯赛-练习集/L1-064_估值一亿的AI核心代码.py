import re

n = int(input())
for i in range(n):
    q = input()
    print(q)

    # 把行首尾的空格全部删掉
    q = q.strip()
    # 消除原文中多余空格, 把相邻单词间的多个空格换成 1 个空格
    q = re.sub(r"\s+", " ", q)
    # 把原文中所有大写英文字母变成小写，除了 I
    q = re.sub(r"(?![I])[A-Z]", lambda pat: pat.group(0).lower(), q)
    # 把标点符号前面的空格删掉
    q = re.sub(r"\s+([^a-zA-Z0-9])", r"\1", q)
    # 避免原文中的 I 被替换成 you, 先用占位符替换 I, 然后再把占位符替换成 you
    # /b 表示单词边界
    q = re.sub(r"\bI\b", r"place_holder", q)
    # 把原文中所有独立的 can you、could you 对应地换成 I can、I could
    q = re.sub(r"\bcan you\b", r"I can", q)
    q = re.sub(r"\bcould you\b", r"I could", q)
    # 把原文中所有独立的 I(占位符) 对应地换成 you
    q = re.sub(r"(place_holder|\bme\b)", r"you", q)
    # 把原文中所有的问号 ? 换成惊叹号 ！
    q = re.sub(r"\?", r"!", q)

    print("AI: %s" % q)