x = 2**1000
ans=0
while x>0:
    ans = ans + (x%10)
    x = int(x//10)
print(ans)
