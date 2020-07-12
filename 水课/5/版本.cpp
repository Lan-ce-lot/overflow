#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<assert.h>
using namespace std;
typedef long long ll;
ll f(int n,int mod)
{
	ll ans=1;
	for(int i=0;i<;i++)
	{
		ans=ans*i%p;
	}
	return ans;
}
int main() 
{  
	ll ans=9;
	
	ll temp=120,temp1;
	for(int i=7;i<=20;i++)
	{
		temp=temp*(i-1);
		ans+=(temp%i);
	}
	cout<<ans;
	return 0; 
}
