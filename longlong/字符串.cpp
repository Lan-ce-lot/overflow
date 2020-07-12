#include<bits/stdc++.h> 

using namespace std;
const int INF=0x3f3f3f3f;

#define N 1000000
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))

char str[N];
int main()
{
	int n,t;
	scanf("%d",&n);
	t=n;
	getchar();
	while(n--)
	{
		int i=0;
		
		while(1)
		{
			str[i]=getchar();
			if(str[i++]=='\n')break;
		}
		int length=strlen(str),cnt=0;
		for(int i=0;i<length;i++)
			str[i]>='0'&&str[i]<='9'?cnt++:i;
		printf("%d\n",cnt);
		M(str);
	} 
	return 0;
}
