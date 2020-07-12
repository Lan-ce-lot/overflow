#include<bits/stdc++.h> 

using namespace std;
int a[10005], ans=0,b[10005],ss=0;
int dfs(int x)
{
	
	if(a[a[x]]==x||b[x]==1)
	{
		b[a[x]]=1;
		return ss;
	}
	b[x]=1;
	ss++;
	dfs(a[x]);
	
	return ss;
}
int main()

{
	int n;
	
	scanf("%d",&n);
	ans=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]!=1)
		{
			ss=0;
			dfs(i);
			ans-=ss;
		}
	}
	printf("%d",ans);
	return 0;

}
