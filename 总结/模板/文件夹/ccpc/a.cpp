#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    for(int cs=1;cs<=T;++cs){
        bool ans=0;
        int n;
        scanf("%d",&n);
        for(int l=1,r,t;l<=n;l=r+1){
            t=n/l,r=n/t;
            ans^=r-l+1&t&1;
        }
        printf("Case %d: ",cs);
        puts(ans?"odd":"even");
    }
}
