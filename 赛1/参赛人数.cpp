#include<bits/stdc++.h> 
using namespace std;
int a[30005],zz[30005],ans=0;
int main()

{
	int n,st;
	scanf("%d%d",&n,&st);
	for(int i=0;i<st;i++)
	{
		int r;
		scanf("%d",&r);
		for(int j=0;j<r;j++)
		{
			int flag=0;
			scanf("%d",&zz[j]);
			if(i==0)
			{
				a[zz[j]]=1;
			}
				
			else
			{
				if(flag==0&&a[zz[j]]==1)
				{
					flag=1;
					for(int x=0;x<r;x++)
					{
						a[zz[x]]=1;
					}
				}
			}
		}	
	}
	 for(int i=0;i<n;i++)
	 {
	 	a[i]==1?ans++:ans;
	 }
	 cout<<ans<<endl;
	return 0; 
}
