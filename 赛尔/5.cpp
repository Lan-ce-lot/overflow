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
		printf("%d\n",a[0]);
		puts("1");
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
	for(int i=0;i<n;i++)
	{
		a[i]==min1?l1++:l1;
		if(a[i]>min1)
		{
			break;
		}
	}
	printf("%d\n",l1+1);
	printf("%d %d",min1,max1);
	return 0;

}
