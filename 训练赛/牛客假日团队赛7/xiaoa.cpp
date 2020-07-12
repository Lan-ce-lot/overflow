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
const int maxn=1090;
int x[maxn],y[maxn];

struct node{
	int x,y,r;
	bool flag=1;
}a[maxn];

int main()
{
	int n,sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].r;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(i==j||a[j].flag==0)continue;
			if((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y)==(a[i].r+a[j].r)*(a[i].r+a[j].r))
			{
				i=j;
				a[j].flag=0;
				sum++;
				if(sum==n-1)
			{
				cout<<a[j].x<<' '<<a[j].y<<endl;
				return 0; 
			}
				i--;
				break;
			}
			
		}
	}
    return 0;
}
