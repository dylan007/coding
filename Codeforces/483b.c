#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

long long int c1,c2,x,y;

long long int check(long long int a)
{
	return (((a-a/x >= c1) && (a-a/y >= c2)) && (a-a/(x*y) >= c1+c2));
}

int main()
{
	scanf("%lld %lld %lld %lld",&c1,&c2,&x,&y);
	long long int high = INT_MAX,low=0,mid;
	while(high>low)
	{
		mid = high+low;
		mid /= 2;
		if(check(mid))
			high = mid;
		else
			low = mid+1;
	}
	printf("%lld\n",high);
	return 0;
}
