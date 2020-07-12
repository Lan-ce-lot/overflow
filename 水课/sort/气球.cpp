#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
using namespace std;
typedef long long ll;
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
struct stu
{
	int yu,qq,gao;
}sb[100000];
bool cmp(stu a,stu b)
{
	return a.gao<b.gao;
}
bool cmpp(stu a,stu b)
{
	return a.yu<b.yu;
}
int b[100000];
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&sb[i].gao);
		sb[i].yu=i;
		sb[i].qq=0;
	}
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	sort(sb,sb+m,cmp);
	sort(b,b+n);
	for(int i=0,j=0;i<m;i++)
			for(;sb[i].gao>=b[j]&&j<n;j++)
				sb[i].qq++;
	sort(sb,sb+m,cmpp);		
	for(int i=0;i<m;i++)
	{
		printf("%d\n",sb[i].qq);
	}
	return 0;

}
