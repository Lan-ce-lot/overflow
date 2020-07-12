#include<bits/stdc++.h> 

using namespace std;
int n,a[105],b[105]; 
int main()

{
	while(~scanf("%d",&n)) 
	{
		int ans=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(2*a[i]==a[j])
				{
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}


	return 0;

}
