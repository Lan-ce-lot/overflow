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
int main()

{
	int n,flag=0,b[1000]={0};
	char c,a[1000];scanf("%d",&n);
	c=getchar();
	gets(a);int l=strlen(a);
	for(int i=0;i<l;i++)
	{
		if(flag==0)
		{
			
			if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='y')

				flag=1;
		}
		else
		{
			if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='y')
			{
				b[i]=1;
			}
		}
			
	}
	for(int i=0;i<l;i++)
		b[i]!=0?i:printf("%c",a[i]);
	return 0;
}
