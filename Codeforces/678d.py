import sys
a,b,n,x = map(int,raw_input().split())
mod = 1000000007
if(a is 1):
	print (n*b + x)%mod
else :
	print (pow(a,n,mod)*x + b*(((pow(a,n,mod) - 1)*pow(a - 1,mod - 2,mod)) % mod))%mod
