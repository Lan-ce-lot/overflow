#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
int rad[N];
int stk[N];

char * cp=(char *)malloc((int)2e8);
inline void in(int &x){
    while(*cp<'0'||*cp>'9')++cp;
    for(x=0;*cp>='0'&&*cp<='9';++cp)x=x*10+*cp-'0';
}

int main(){
    fread(cp,1,(int)2e8,stdin);
    int T;
    in(T);
    for(int cs=1;cs<=T;++cs){
        int n;
        in(n);
        for(int i=1;i<=n;++i)in(rad[i]);
        int top=0;
        int ans=0;
        for(int j=n;j;--j){
            while(top&&stk[top-1]-j<rad[j]){
                int i=stk[--top];
                ans^=max((2*j-i)-(i-rad[i]),0);
            }
            stk[top++]=j;
        }
        printf("Case %d: %d\n",cs, ans);
    }
}
