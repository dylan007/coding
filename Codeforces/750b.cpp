/*=======================
Author    : Shounak Dey
Filename  : 750b.cpp
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
	int n;
	cin >> n;
	int pos=0,vh=0;
	while(n--)
	{
		int x;
		string s;
		cin >> x >> s;
		if(s!="South" && pos==0)
		{
			cout << "NO" << endl;
			return 0;
		}
		if(s!="North" && pos==2)
		{
			cout << "NO" << endl;
			return 0;
		}
		if(s=="South")
		{
			vh += x;
			if(vh>20000)
				return cout <<"NO" << endl,0;
			if(vh==20000)
				pos = 2;
			else
				pos = 1;
		}
		if(s=="North")
		{
			vh -= x;
			if(vh<0)
				return cout <<"NO" << endl,0;
			if(vh==0)
				pos = 0;
			else
				pos = 1;	
		}
		//cout << pos << " " << vh << endl;
	}
	if(pos==0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
