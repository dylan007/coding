//Shounak Dey
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define PB push_back
#define MK make_pair 
#define SZ(a) (int)(sizeof(a))
#define F first
#define S second
#define REP(i,a,b) for(int i=a;i<b;i++)
#define READ(n) scanf("%d",&n)
#define READL(n) scanf("%lld",&n)
#define SORTV(a) sort(a.begin(),a.end())
#define TESTCASE int Test;cin >> Test;while(Test--)


int main()
{
	TESTCASE
	{
		string a;
		cin >> a;
		int count=0;
		for(int i=0;i<a.length();i++)
			count += (a[i]=='4' || a[i]=='7');
		cout << a.length()-count << endl;
	}
	return 0;
}

