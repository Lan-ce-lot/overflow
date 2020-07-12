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
struct bi
{
	int d[1000];
	int len;
	bi(){
		memset(d,0,sizeof(d));
		len=0;
	}
};
bi change(char str[])
{
	bi a;
	a.len=strlen(str);
	for(int i=0;i<a.len;i++)
	{
		a.d[i]=str[a.len-i-1]-'0';
	}
	return a;
}
bi add(bi a,bi b)
{
	bi c;
	int carry =0;
	for(int i=0;i<a.len||i<b.len;i++)
	{
		int temp=a.d[i]+b.d[i]+carry;
		c.d[c.len++]=temp%10;
		carry=temp/10;
	 } 
	 if(carry!=0)
	 	c.d[c.len++]=carry;
	return c;
}
bi sub(bi a,bi b)
{
	bi c;
	for(int i=0;i<a.len||i<b.len;i++)
	{
		if(a.d[i]<b.d[i])
		{
			a.d[i+1]--;
			a.d[i]+=10;
		}
		c.d[c.len++]=a.d[i]-b.d[i];
	}
	while(c.len-1>=1&&c.d[c.len-1]==0)
	c.len--;
	return c;
}
void print(bi a)
{
	for(int i=a.len-1;i>=0;i--)
	{
		printf("%d",a.d[i]);
	}
}
char st1[1000],st2[1000],st3[1000],st4[1000]; 
int main()
{
	int t;
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s%s%ls",st1,st2,st3,st4);
		bi a1=change(st1);
		bi b1=change(st2);
		bi c1= change(st3);
		bi d1=change(st4);
		print(add(add(a1,b1),add(c1,d1)));
	}
	return 0;
}
