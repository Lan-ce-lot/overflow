#!/usr/bin/python
# encoding:utf-8
"""
@author: lance
@version: 1.0.0
@license: Apache Licence
@file: t1.py
@time: 2021/4/5 21:16
"""

from cyaron import *  # 引入CYaRon的库 `pip install cyaron`

test_data = IO(file_prefix="test", data_id=4)  # 生成 test4.in/out 测试数据
L = 1e4
R = 1e4
N = 1e4
# n = randint(1, 1e4)
n = int(1500)
e = randint(1, L)
s = randint(-L, e - 1)

test_data.input_writeln(n, s, e)
set0 = set()
y = s
x = randint(1, N)
set0.add(s)
test_data.input_writeln(x, y)
for i in range(n - 1):
    y = randint(s, e)
    while y in set0:
        y = randint(s, e)
    x = randint(1, N)
    set0.add(y)
    test_data.input_writeln(x, y)
# 程序编译的可执行文件路径
test_data.output_gen("D:\\work\\C++\\old\\master\\算法\\tm\\nn.exe")
if __name__ == '__main__':
    pass
