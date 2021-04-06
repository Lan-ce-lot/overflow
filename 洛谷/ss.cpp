/*************************************************************************
 > FileName:
 > Author:      huangchangsheng
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll inff = 0x3f3f3f3f3f3f3f3f;
#define FOR(i,a,b) for(int i(a);i<=(b);++i)
#define FOL(i,a,b) for(int i(a);i>=(b);--i)
#define REW(a,b) memset(a,b,sizeof(a))
#define inf int(0x3f3f3f3f)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%I64d",&a)
#define sd(a) scanf("%lf",&a)
#define ss(a) scanf("%s",a)
#define mod int(1e9+7)
#define lc (d<<1)
#define rc (d<<1|1)
#define P pair<int,int>
#define pi acos(-1)

const int MX=1000010;
int a[MX],b[MX]; 

int main()
{
//    freopen("blash.in","r",stdin),freopen("blash.out","w",stdout);
    int x,n;
    while(scanf("%d%d",&x,&n)!=EOF)
    {
        int tot=1,la=0,lb=0,ra=1,rb=1;
        while(1)
        {
            if(tot==n) {
                printf("%d\n",x);
                break;
            }
            a[++la]=2*x+1;
            b[++lb]=3*x+1;
            if(a[ra]<b[rb]) {
                x=a[ra++];
            }
            else if(b[rb]<a[ra]) {
                x=b[rb++];
            }
            else {
                x=a[ra++];
                rb++;
            }
            tot++;
        }
    }
    return 0;
}


