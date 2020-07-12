#include<cstdio>
const int N=200;
typedef long long LL;
int n;LL f[N],g[N],gc,Ans;
LL gcd(LL u,LL v){return v?gcd(v,u%v):u;}
int main(){
    scanf("%d",&n);
    f[100]=1;
    for(int i=1;i<=n;i++){
        for(int j=5;j<=195;j++)
        g[j]=f[j-1]+f[j]+f[j+1]+f[j+2];
        for(int j=5;j<=195;j++)f[j]=g[j];
    }
    for(int i=100;i<=199;i++)Ans=Ans+f[i];
    gc=gcd(Ans,1ll<<(n*2));
    printf("%lld/%lld\n",Ans/gc,(1ll<<(n*2))/gc);
}
