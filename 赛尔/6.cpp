#include<bits/stdc++.h> 

using namespace std;
int a[1000005],max1,min1;
int main()

{
	
	int n,l1=0,l2=0;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n==1)
	{
		puts("1");
		printf("%d\n",a[0]);
		
		return 0;
	}
	sort(a,a+n);
	max1=a[n-1];
	min1=a[0];
	if(max1==min1)
	{
		printf("%d\n",n);
		printf("%d\n",a[0]);
		return 0;
	}
	for(int i=0,j=n-1;;)
	{
		int t=(i+j)/2;
		if(a[t]==a[0])
		{
			if(a[t+1]>a[0])
			{
				l1=t+1;
				break;
			}
			else
			{
				i=t+1;
			}
		}
		if(a[t]>a[0])
		{
			if(a[t-1]==a[0])
			{
				l1=t-1;
				break;
			}
			else
			{
				j=t-1;
			}
		}
	}
	printf("%d\n",l1+1);
	printf("%d %d\n",min1,max1);
	return 0;
}
