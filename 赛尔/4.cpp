#include<bits/stdc++.h> 
#include<algorithm>
using namespace std;
int a[1005],ans[1005],l[200005],max1=0;
int main()

{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n);int t=0;
	
	if(n==2)
	{
		puts("1");
		return 0;
	}
	if(n<2)
	{
		puts("0");
		return 0;
	}
	for(int i=0,j=n-1;i<j;i++,j--)
	{
		ans[t++]=a[i]+a[j];
	}
		for(int i=0,j=n-2;i<j;i++,j--)
	{
		ans[t++]=a[i]+a[j];
	}
	sort(ans,ans+t,greater<int>());

	for(int i=0;i<t;i++)
	{
		
		for(int j=1;j<t;j++)
		{
			if(ans[i]==ans[j])
			{
				l[ans[i]]++;
			}
		}
	}
	sort(l,l+ans[0]+1,greater<int>());
	printf("%d",l[0]);
	return 0;
}
