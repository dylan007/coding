/*=======================
Author    : Shounak Dey
Filename  : 982b.cpp
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
	priority_queue<int> maxh;
	priority_queue<int,vector<int>,greater<int>> minh;
	int n;
	cin >> n;
	int x;
	map<int,int> pos;
	REP(i,n){
		cin >> x;
		minh.push(x);
		pos[x] = i;
	}
	string a;
	cin >> a;
	REP(i,2*n){
		if(a[i]=='0'){
			int temp = minh.top();
			minh.pop();
			maxh.push(temp);
			cout << pos[temp]+1 << " ";
		}
		else{
			int temp = maxh.top();
			maxh.pop();
			cout << pos[temp]+1 << " ";	
		}
	}
	cout << endl;
	return 0;
}