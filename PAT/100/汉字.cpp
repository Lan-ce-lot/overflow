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
int main()
{
	int n;
	char a[200],c;
	scanf("%d",&n);	c=getchar();
	while(n--)
	{
		int count=0;
		gets(a);
		for(int i=0;i<strlen(a);i++)
			if(a[i]<0||a[i]>127)
				count++;
		 printf("%d\n",count/2);/*��Ϊ�����ڼ������ռ�����ֽڣ�����һ�����ֻ�ѭ�����Ρ�*/
	}
	return 0;
}
