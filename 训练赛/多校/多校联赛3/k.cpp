#include <iostream>
 #include <algorithm>
using namespace std;
const int nmax=1000+5;
int a[nmax][2];
int dp[nmax];
 
int main() {
	int n,t,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=0;i<n;i++){
           cin>>a[i][1];		
		}
		int ans=0;
		for(int z=0;z<k;z++)
		{
			int tmp,f;
		dp[0]=a[0][1];
		for(int i=1;i<n;i++){
			dp[i]=a[i][1];//dp[i]不能初始化为0;
			for(int j=0;j<i;j++){
				if(a[j][1]<=a[i][1]){
//					if(dp[i]<dp[j]+a[i][1])
//					{
//						a[i][0]=1;
//						
//					}
					dp[i]=max(dp[i],dp[j]+a[i][1]);
					
				}
			}
			
		}
		int zz=0;
			for(int i=0;i<n;i++)
			{
				if(a[i][0]==0)
				{
					a[zz][0]=0;
					a[zz++][1]=a[i][1];
					
				}
				
			}
			n=zz;
		ans+=*max_element(dp,dp+n);
		}
		cout<<ans<<endl;
	}
	return 0;
}
