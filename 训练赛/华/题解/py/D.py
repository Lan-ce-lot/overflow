n=int(input())
while(n):
    s=input()
    sum=s.count('0')+s.count('4')+s.count('6')+s.count('8')*2+s.count('9')
    print(sum)
    n=n-1
