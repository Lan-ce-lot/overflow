#include<bits/stdc++.h>
#define debug(x) cout << "[" << #x <<": " << (x) <<"]"<< endl
#define pii pair<int,int>
#define clr(a,b) memset((a),b,sizeof(a))
#define rep(i,a,b) for(int i = a;i < b;i ++)
#define pb push_back
#define MP make_pair
#define LL long long
#define ull unsigned LL
#define ls i << 1
#define rs i << 1 + 1
#define INT(t) int t; scanf("%d",&t)

using namespace std;

int main() {
    int t; scanf("%d",&t);
    while(t --){
        LL l,r,k; scanf("%lld%lld%lld",&l,&r,&k);
        if(k % 2 == 1){
            printf("%lld\n",r - l + 1);
        }
        else {
            LL ans1 = 0,ans2 = 0;
            -- l;
            if(l < k)
                ans1 = l + 1;
            else {
                LL tmp = (l - k + 1) / (k + 1);
                LL xs = l - k + 1 - tmp * (k + 1);
                ans1 = k + tmp * k + l - (tmp * (k + 1) + k - 1) - (xs != 0);
            }
            if(r < k)
                ans2 = r + 1;
            else{
                LL tmp = (r - k + 1) / (k + 1);
                LL xs = r - k + 1 - tmp * (k + 1);
                ans2 = k + tmp * k + r - (tmp * (k + 1) + k - 1) - (xs != 0);
            }
//            debug(ans1); debug(ans2);
            printf("%lld\n",ans2 - ans1);
        }
    }
    return 0;
}
