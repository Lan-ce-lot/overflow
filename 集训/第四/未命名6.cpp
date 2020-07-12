#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100010],n,l,r,ans1,ans2,p;
int main()
{
    while(~scanf("%lld",&n))
    {
        for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
        ans1=ans2=0;  
        l=1;r=1e6;  //l是左边的即时位置.r是右边的人的即时位置
        p=-1;
        for(ll i=1;i<=n;i++)
        {
            if(a[i]<=500000)
            {
                ans1+=a[i]-l;
                l=a[i];     //更新即时位置
            }
            else
            {
                p=i;
                break;  
            }
        }
        if(p!=-1)       //如果需要朋友跑，进行倒序遍历
        {
            for(ll i=n;i>=p;i--)
            {
                ans2+=r-a[i];
                r=a[i];
            }
        }
        printf("%lld\n",max(ans1,ans2)); //比较输出答案
    }
    return 0;
}

