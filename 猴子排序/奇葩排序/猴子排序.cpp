#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;
int n;
int num[1005],res[1005];
bool used[1005];
bool monkey_sort()
{
	memset(used,0,sizeof(used));
	for(int i=1;i<=n;i++)
	{
		int t=rand()%n+1;
		while(used[t])
		{
		t=rand()%n+1;
		}
		res[t]=num[i];
		used[t]=1;
	}
	for(int i=2;i<=n;i++)
	{
		if(res[i]<res[i-1])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
   {
   	scanf("%d",&num[i]);
   }
   int tot=0;
   while(monkey_sort()!=1)
   {
   tot++;
   }
   for(int i=1;i<=n;i++)
   {
   	cout<<res[i]<<" ";
   }
   cout<<'\n';
   printf("运行了%d次",tot);
   return 0;
}
