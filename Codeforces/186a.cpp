/*=======================
Author    : Shounak Dey
Filename  : 186a.cpp
=======================	*/

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define PB push_back
#define MK make_pair 
#define SZ(a) (int)(sizeof(a))
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define read(n) scanf("%d",&n)
#define readl(n) scanf("%lld",&n)
#define readul(n) scanf("%llu",&n);


#define SORTV(a) sort(a.begin(),a.end())
#define TEST int Test;cin >> Test;while(Test--)
#define gcd(a,b) __gcd(a,b)
#define ffs(a) __builtin_ffs(a) // find first set
#define clz(a) __builtin_clz(a) // count leading zeroes
#define ctz(a) __builtin_ctz(a) // count trailing zeroes
#define popc(a) __ builtin_popcount(a) // count set bits
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)


#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }

vector<string> split(const string& s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c))
		v.emplace_back(x);
	return move(v);
}

void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
	cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
	err(++it, args...);
}

int main()
{
	string a,b;
	cin >> a >> b;
	int f=0;
	if(a.length() != b.length())
	{
		cout << "NO" << endl;
		return 0;
	}
	for(int i=0;i<a.length();i++)
	{
		if(a[i] != b[i])
			f++;	
	}
	if(f!=2 && f!=0){
		cout << "NO" << endl;
		return 0;
	}
	int l,r;
	if(f==0)
	{
		cout << "YES" << endl;
		return 0;
	}
	l = -1;
	r = -1;
	for(int i=0;i<a.length();i++)
	{
		if(a[i] != b[i])
		{
			if(l<0)
				l = i;
			else
				r = i;
		}
	}
	//cout << l << " " << r << endl;
	if(a[l]==b[r] && a[r]==b[l])
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
