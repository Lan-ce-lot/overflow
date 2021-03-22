#include<cstdio>
#include<algorithm>
#define N 100001
using namespace std;
int j,n,ans,a[N];
int main(){
	scanf("%d",&n);
	for(int i=0 ;i<n ;i++) scanf("%d",&a[i]);
	
	sort(a,a+n); 
	for(j=n-1,ans=1 ;j>=0 ;j--,ans++){
		if(a[j]<=ans)break;
	} 
	printf("%d\n",ans-1);
	
	return 0;
} 
