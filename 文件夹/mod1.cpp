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
	int n,t;
	while(~scanf("%d%d",&n,&t))
	{
		int b=abs(n);
		int i=0,a[1000];
		do
		{
			a[i]=b%t;
			b/=t;
			i++;
		}while(b);
		n>0?n:printf("-");
		while(i--)
		{
			
			if(i)
				
				a[i]>=10?printf("%c",a[i]+'A'-10):printf("%d",a[i]);
				
			else
				a[i]>=10?printf("%c\n",a[i]+'A'-10):printf("%d\n",a[i]);
				
		}

		
	 } 
	
	


	return 0;

}
