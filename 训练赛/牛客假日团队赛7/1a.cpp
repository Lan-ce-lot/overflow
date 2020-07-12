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
const int maxn=1100;

struct node{
	int x,y,r;
	int flag;
}a[maxn];
bool cmp(node a,node b)
{
	return a.flag>b.flag;
}
int main()
{
	int n,sum=0,x_1,y_1,i_1=0,id=1;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].r;
		a[i].flag=0;
	}
	for(int i=0;i<n;i++)
	{
		if(a[i].x==0&&a[i].y==0)
		{
			i_1=i;
			a[i].flag++;
			break;
		}
	}
	while(id)
	{
		id=0;
		for(int i=0;i<n;i++)
		{
			if(i==i_1||a[i].flag)continue;
			if((a[i].x-a[i_1].x)*(a[i].x-a[i_1].x)+(a[i].y-a[i_1].y)*(a[i].y-a[i_1].y)==(a[i].r+a[i_1].r)*(a[i].r+a[i_1].r))
			{
				a[i].flag=a[i_1].flag+1;
				i_1=i;
				i=-1;
				id=1;
				break;
				
			}
			
		}
	}
	
	
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//		{
//			if(i==j||a[j].flag)continue;
//			if((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y)==(a[i].r+a[j].r)*(a[i].r+a[j].r))
//			{
//			
//				a[j].flag=a[i].flag+1;
//				i=j;
//				
//
//				i--;
//				break;
//			}
//			
//		}
//	}
	sort(a,a+n,cmp);
	cout<<a[0].x<<' '<<a[0].y<<endl;
    return 0;
}
