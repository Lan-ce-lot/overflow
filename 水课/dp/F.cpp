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
ll dp[1005],t[2],flag[1005];
string str1,str2,str3;
int main()

{
	cin>>str1>>str2;
	for(int i=0;i<str2.size();i++)
	{
		if(str2[i]>='a'&&str2[i]<='z')
		{
			str2[i]-=32;
			flag[str2[i]]=1;	
		}
		else
		{
			flag[str2[i]]=1;
		}
	}
	
	for(int i=0;i<str1.size();i++)
	{
		if(str1[i]>='a'&&str2[i]<='z')
		{
			str1[i]-=32;
		}
		if(flag[str1[i]]==0)
		{
			str3+=str1[i];
			flag[str1[i]]=1;
		}
	}
	cout<<str3<<endl;;
	return 0;
	
}
   
