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
	int a[10],b[10],flag=1;
	
	for(int i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	 } 
	for(int i=1;i<10;i++)
	{
		if(a[i]==0)
		{
			continue;
		}
			for(;a[i];a[i]--)
			{
						
				printf("%d",i);
				if(flag==1)
				{
					while(a[0]--)
						printf("0");
					flag=0;	
				}
				
			}
			
	}

//	system("pause");
	return 0;

}
