#include<bits/stdc++.h> 

using namespace std;
const int INF=0x3f3f3f3f;
#define N 1000000
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
char str[N];
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",str);
		int length=strlen(str),cnt=0;
		for(int i=0;i<length;i++)
			str[i]>='0'&&str[i]<='9'?cnt++:i;
		printf("%d\n",cnt);
	} 


	return 0;

}
