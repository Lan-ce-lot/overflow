#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#define ll  long long 
using namespace std;
const ll mod = 998244353;
const int N=1e6+5;
ll num[N];
vector<int> V[500];
int  main()
{
	int t,n,k;
	scanf("%d",&t);
	while(t--)
	{
		
		scanf("%d%d",&n,&k);
		int len=2*n*pow(2,k);
		for(int i=1;i<=len;i++)
		{
			scanf("%d",&num[i]);
		}
		for(int i=1;i<=2*n;i++)
		{
			for(int j=2*n-i+1;j<=len;j+=4*n)
			{
				V[i].push_back(num[j]);
				V[i].push_back(num[j+(2*i)-1]);
			}
		}
		for(int i=1;i<=2*n;i++)
		{
			for(int j=0;j<V[i].size();j++)
			{
				
				cout<<V[i][j]<<' ';
			} 
			cout<<endl;
		}
		
		
	 } 
	 
	
}
