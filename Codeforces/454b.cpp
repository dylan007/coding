#include<iostream>

using namespace std;

int main()
{
	long int n,a[100002],i,t=0,b=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(i>0&&a[i]<a[i-1]) 
		{
			t++;
			b=i;
		}
	}
	if(t==0) cout<<0;
	else 
	{
		if(t==1&&a[n-1]<=a[0]) 
			cout<<n-b;
		else 
			cout<<-1;
	}
	cout << endl;
	return 0;
}

