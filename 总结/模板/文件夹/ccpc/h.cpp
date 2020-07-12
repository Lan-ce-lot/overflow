#include<bits/stdc++.h>
using namespace std;

char * cp=(char *)malloc((int)2e7);
inline void in(int &x){
    while(*cp<'0'||*cp>'9')++cp;
    for(x=0;*cp>='0'&&*cp<='9';++cp)x=x*10+*cp-'0';
}
char * buf=(char *)malloc((int)1e7), * op=buf;
void ou(int x){
    if(x){
        ou(x/10);
        *op++='0'+x%10;
    }
}
void out(int x){
    if(x)ou(x);
    else *op++='0';
    *op++='\n';
}

typedef long long ll;
const int P=1e9+7;

const int N=1e5+5;
struct Seg{
    ll valSum, pwrSum;
    ll flagVal, flagPwr, flagRev;
}segt[N<<2];
#define lson node*2,l,(l+r)/2
#define rson node*2+1,(l+r)/2+1,r
void out(int node,int l,int r){
    Seg & u=segt[node];
    printf("[%d,%d]={valSum=%lld, pwrSum=%lld, flagVal=%lld, flagPwr=%lld, flagRev=%lld}\n", l, r, u.valSum, u.pwrSum, u.flagVal, u.flagPwr, u.flagRev);
}
void clearFlag(Seg & u){
    u.flagVal=0, u.flagPwr=1, u.flagRev=0;
}
void build(int node,int l,int r){
    Seg & u=segt[node];
    u.valSum=0, u.pwrSum=r-l+1;
    clearFlag(u);
    if(l!=r)build(lson), build(rson);
}
void paint(ll val, ll pwr, ll rev, int node,int l,int r){
    Seg & u=segt[node];
    u.valSum=(u.valSum*pwr+rev*(r-l+1)+val*pwr%P*u.pwrSum)%P;
    u.pwrSum=u.pwrSum*pwr%P*pwr%P;
    u.flagVal=(u.flagVal+val*u.flagPwr)%P;
    u.flagPwr=u.flagPwr*pwr%P;
    u.flagRev=(u.flagRev*pwr+rev)%P;
}
void pushdown(int node,int l,int r){
    Seg & u=segt[node];
    if(u.flagVal||u.flagPwr!=1||u.flagRev){
        paint(u.flagVal, u.flagPwr, u.flagRev, lson);
        paint(u.flagVal, u.flagPwr, u.flagRev, rson);
        clearFlag(u);
    }
}
void pushup(int node,int l,int r){
    Seg & u=segt[node];
    u.valSum=(segt[node*2].valSum+segt[node*2+1].valSum)%P;
    u.pwrSum=(segt[node*2].pwrSum+segt[node*2+1].pwrSum)%P;
}
void modify(ll val,ll pwr,ll rev,int L,int R,int node,int l,int r){
    if(L<=l&&r<=R)paint(val,pwr,rev,node,l,r);
    else{
       pushdown(node,l,r);
       if(L<=(l+r)/2)modify(val,pwr,rev,L,R,lson);
       if(R>(l+r)/2)modify(val,pwr,rev,L,R,rson);
       pushup(node,l,r);
    }

    //printf("modify(val=%lld, pwr=%lld, rev=%lld, L=%d, R=%d):\n", val, pwr, rev, L, R);
    //out(node,l,r);
}
int query(int L,int R,int node,int l,int r){
    if(L<=l&&r<=R)return segt[node].valSum;
    else{
        pushdown(node,l,r);
        int ans=0;
        if(L<=(l+r)/2)ans=(ans+query(L,R,lson))%P;
        if(R>(l+r)/2)ans=(ans+query(L,R,rson))%P;
        return ans;
    }
}
int main(){
    fread(cp,1,(int)2e7,stdin);
    int T;
    in(T);
    for(int cs=1;cs<=T;++cs){
        *op++='C', *op++='a', *op++='s', *op++='e', *op++=' ';
        ou(cs);
        *op++=':', *op++='\n';

        int n,m;
        in(n),in(m);

        build(1,1,n);

        int l,r,d;
        while(m--){
            while(*cp<'a'||*cp>'z')++cp;
            if(*cp=='w'){
                in(l),in(r),in(d);
                modify(d,10,d,l,r,1,1,n);
            }
            else{
                in(l),in(r);
                out((query(l,r,1,1,n)+P)%P);
            }
        }
    }
    fwrite(buf,1,op-buf,stdout);
}
