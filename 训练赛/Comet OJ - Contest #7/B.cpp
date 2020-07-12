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
const int maxn=1005;


int a[4],ans=0;
int main()
{
    for(int i=0;i<4;i++)
    {
    	cin>>a[i];
    	
    	
    	
	}
	for(int i=0;i<4;i++)
	{
		int temp=0;
		if(a[0]==1)
		{
			break;
		}
		else
		{
			temp=a[3];
			a[3]=a[2];
			a[2]=a[1];
			a[1]=a[0];
			a[0]=temp;
		}
	}

	if(a[1]==2&&a[2]==4)
	{
		ans=1;
	}
	if(a[1]==2&&a[2]==3)
	{
		ans=0;
	}
	if(a[1]==3&&a[2]==4)
	{
		ans=1;
	}
	if(a[1]==3&&a[2]==2)
	{
		ans=1;
	}
	if(a[1]==4&&a[2]==2)
	{
		ans=1;
	}
	if(a[1]==4&&a[2]==3)
	{
		ans=2;
	}			
	cout<<ans<<endl;
    return 0;
}
