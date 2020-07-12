x= 2
n=int(input());ab=ba=bc=ca=cb=0;ac=1
for i in range(1,n):
    if i&1:      
        ab+=x//3+1
        bc+=x//3+1
        ca+=x//3
    else :
        ac+=x//3+1
        ba+=x//3
        cb+=x//3
    x<<=1
print(f"A->B:{ab}")
print(f"A->C:{ac}")
print(f"B->A:{ba}")
print(f"B->C:{bc}")
print(f"C->A:{ca}")
print(f"C->B:{cb}")
print(f"SUM:{2**n-1}")
