/*=======================
Author    : Shounak Dey
Filename  : 580c.cpp
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

void bfs(vector<vector<int>> adj,vector<int> &color,vector<int> &leaf,vector<int> &count,int n,int m,vector<int> &visited){
	queue<int> q;
	q.push(0);
	visited[0] = 1;
	count[0] = color[0];
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		visited[curr] = 1; 
		if(count[curr]>m){
			REP(i,adj[curr].size()){
				if(!visited[adj[curr][i]])
					leaf[curr] = 0;
			}
			continue;
		}
		REP(i,adj[curr].size()){
			if(!visited[adj[curr][i]]){
				leaf[curr] = 0;
				q.push(adj[curr][i]);
				if(color[adj[curr][i]]==0)
					count[adj[curr][i]] = 0;
				else
					count[adj[curr][i]] = color[adj[curr][i]] + count[curr];
			}
		}
	}
	return;
}

int main()
{
	int n,m;
	cin >> n >> m;
	vector<vector<int>> adj(n,vector<int>());
	vector<int> color(n,0);
	REP(i,n)
		cin >> color[i];
	REP(i,n-1){
		int x,y;
		cin >> x >> y;
		x--;y--;
		adj[x].PB(y);
		adj[y].PB(x);
	}
	vector<int> leaf(n,1),count(n,0);
	vector<int> visited(n,0);
	bfs(adj,color,leaf,count,n,m,visited);
	int c=0;
	REP(i,n){
		if(leaf[i] && visited[i]){
			// error(i,count[i]);
			c += (count[i]<=m);
		}
	}
	cout << c << endl;
	return 0;
}