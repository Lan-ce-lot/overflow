//其实直接二分就好了
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,t,n,i,l,r,mid,w,q,a[5000000];
int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a + 1, a + n + 1);
    for(i=1;i<=n;i++)
    {
        l=i+1;r=n;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(a[i]+m<=a[mid])
              r=mid-1;
            else
              l=mid+1;
        }
        w=l;//找出后面所指定连续数的第一位
        l=i+1;r=n;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(a[i]+m<a[mid])
              r=mid-1;
            else
              l=mid+1;
        }
        q=l;//找出后面所指定连续数的末位+1
        t+=q-w;//直接减出连续串的长度
    }
    printf("%lld",t);
    return 0;
}
