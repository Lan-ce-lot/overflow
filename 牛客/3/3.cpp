#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[100005]={0},dp[100005]={0},b,n,i,j;
    scanf("%d",&n);
    scanf("%d",&a[1]);
    dp[1]=a[1];
    for(i=2;i<=n;i++){
        scanf("%d",&a[i]);
        for(j=1;j<i;j++){
            if(a[i]<a[j]&&dp[j])dp[i]=max(dp[i],dp[j]^a[i]);
        }
    }
    if(dp[n]!=0)printf("%d",dp[n]);
    else printf("-1");
    return 0;
}
