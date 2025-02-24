/*=======================
Author    : Shounak Dey
Filename  : chefham.cpp
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


int get_next(vector<int> arr,int index)
{
	return arr[(index+1)%arr.size()];
}

int main()
{
	TEST{	
		int n;
		cin >> n;
		vector<int> x(n);
		vector<int> count(100001,0);
		map<int,vector<int>> index;
		REP(i,n)
		{
			cin >> x[i];
			count[x[i]]++;
			if(index.find(x[i]) == index.end())
				index.insert(MK(x[i],vector<int>(1,i)));
			else
				index[x[i]].PB(i);
		}
		vector<int> ones, twos;
		REP(i,100001)
		{
			if(count[i]==1)
				ones.PB(i);
			else if(count[i] == 2)
				twos.PB(i);
		}
		// for(auto it: index){
		// 	cout << it.first << it.second.size() <<endl;
		// 	for(auto p: it.second)
		// 		cout << p << " ";
		// 	cout << endl;
		// }
		// cout << "Ones" << endl;
		// for(auto it: ones) cout << it << " ";
		// cout << endl << "Twos" << endl;
		// for(auto it: twos) cout << it << " ";
		// cout << endl;
		vector<int> out(n);
		if(ones.size()==1 && twos.size()==1)
		{
			int p1 = index[ones[0]][0];
			int p2 = index[twos[0]][0];
			index[ones[0]][0] = p2;
			index[twos[0]][0] = p1;
			for(auto it:index)
			{
				for(int i=0;i<it.second.size();i++)
					out[it.second[i]] = it.first;
			}
		}
		else if(ones.size()==1 && twos.size()>1)
		{
			int p1 = index[ones[0]][0];
			int p2 = index[twos[0]][0];
			index[ones[0]][0] = p2;
			index[twos[0]][0] = p1;
			int l=twos.size();
			for(int i=1;i<l;i++)
				index[twos[i]].swap(index[twos[(i+2)%l]]);
			for(auto it:index)
			{
				for(int i=0;i<it.second.size();i++)
					out[it.second[i]] = it.first;
			}
		}
		else if(twos.size()==1 && ones.size()>1)
		{
			int p1 = index[ones[0]][0];
			int p2 = index[twos[0]][0];
			index[ones[0]][0] = p2;
			index[twos[0]][0] = p1;
			p1 = index[ones[1]][0];
			p2 = index[twos[0]][1];
			index[ones[1]][0] = p2;
			index[twos[0]][1] = p1;
			int l=ones.size();
			for(int i=1;i<l;i++)
				index[ones[i]].swap(index[ones[(i+2)%l]]);
			for(auto it:index)
			{
				for(int i=0;i<it.second.size();i++)
					out[it.second[i]] = it.first;
			}
		}
		else
		{
			int l=ones.size();
			for(int i=1;i<l;i++)
				index[ones[i]].swap(index[ones[(i+2)%l]]);
			l = twos.size();	
			for(int i=1;i<l;i++)
				index[twos[i]].swap(index[twos[(i+2)%l]]);
			for(auto it:index)
			{
				for(int i=0;i<it.second.size();i++)
					out[it.second[i]] = it.first;
			}
		}
		for(auto it: out)
			cout << it << " ";
		cout << endl;
	}	
	return 0;
}
