import math
q = eval(input())
print(type(q))
for i in range(q):
    n = eval(input())
    ls = map(int,input().split())
    sums = sum(ls)
    x = math.ceil(sums/n)
    print(x)
