#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<bitset>
#include<string>
#include<cmath>
#include<sstream>
using namespace std;
typedef long long ll;
const double pi=acos(-1.0);
const int eps=1e-10;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn=1005;//20922789888000  16!
ll t,n,ans=0;
ll ADA(int n)
{
	if(n==1)return 1;
	if(n==2)return 2;
	return (n-1)*(ADA(n-1)+ADA(n-1));
}

int a[20];
int main()
{
	cout<<ADA(16)<<endl;
    cin>>t;
    while(t--)
    {
    	cin>>n;
    	for(int i=0;i<n;i++)
    	{
    		cin>>a[i];
			 
		}
		cout<<ans<<endl;
	}
    return 0;
}
