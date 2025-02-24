/*=======================
Author    : Shounak Dey
Filename  : 1096g.cpp
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
#define popc(a) __builtin_popcount(a) // count set bits
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

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> &a,bool inv){
    ll n = a.size();
    if(n==1)
        return;
    vector<ll> a0(n/2),a1(n/2);
    for(ll i=0;(2*i)<n;i++){
        a0[i] = a[2*i];
        a1[i] = a[2*i + 1];
    }
    fft(a0,inv);
    fft(a1,inv);
    double ang = 2 * PI / n * (inv?-1:1);
    cd w(1),wn(cos(ang),sin(ang));
}

int main()
{
	fast_io;
    ll n,k;
    cin >> n >> k;

    return 0;
}