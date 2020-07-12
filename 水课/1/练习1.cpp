#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
using namespace std;
typedef long long ll;
int main()
{
	char str[10001];
	gets(str);
	int l=strlen(str),count=0,c1=0,flag=0;
	for(int i=l-1;i>=0;i--)
		if(str[i]==' ')
		{
			count++;
			if(str[i-1]!=' '&&flag==0&&str[l-1]==' ')c1=count,flag=1;
		}

	for(int i=l-2;i>0;i--)
		if(str[i]==' '&&str[i+1]!=' ')
		{
			cout<<l-1-i-c1;
			return 0;
		}
	cout<<l-count;
	return 0;
}
