#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
ll a[100010],sum[100010],add[100010];
int L[100010],R[100010];
int pos[100010];
int n,m,t;
//
void change(int l,int r,ll d)
{
    int p=pos[l],q=pos[r];
    if (p==q)
    {
        for (int i=l; i<=r; i++)
            a[i]+=d;
        sum[p]+=d*(r-l+1);
    }
    else
    {
        for (int i=p+1; i<=q-1; i++)
            add[i]+=d;
        for (int i=l; i<=R[p]; i++)
            a[i]+=d;
        sum[p]+=d*(R[p]-l+1);
        for (int i=L[q]; i<=r; i++)
            a[i]+=d;
        sum[q]+=d*(r-L[q]+1);
    }
}
ll ask(int l,int r)
{
    int p=pos[l],q=pos[r];
    ll ans=0;
    if (p==q)
    {
        for (int i=l; i<=r; i++)
            ans+=a[i];
        ans+=add[p]*(r-l+1);
    }
    else
    {
        for (int i=p+1; i<=q-1; i++)
            ans+=sum[i]+add[i]*(R[i]-L[i]+1);
        for (int i=l; i<=R[p]; i++)
            ans+=a[i];
        ans+=add[p]*(R[p]-l+1);
        for (int i=L[q]; i<=r; i++)
            ans+=a[i];
        ans+=add[q]*(r-L[q]+1);
    }
    return ans;
}

//t -> num 分块个数
//L R 表示i这块的左端点
//pos[] -> belong[],表示i属于哪一块
//add
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1; i<=n; i++)
        scanf("%lld",&a[i]);
    t=(int)sqrt((double)n);
    for (int i=1; i<=t; i++)
    {
        L[i]=(i-1)*t+1;
        R[i]=i*t;
    }
    if (R[t]<n)
        t++,L[t]=R[t-1]+1,R[t]=n;
    for (int i=1; i<=t; i++)
        for (int j=L[i]; j<=R[i]; j++)
        {
            pos[j]=i;
            sum[i]+=a[j];
        }
        for (int i = 0; i < n; i++)
            printf("%lld\n", sum[i]);
    while (m--)
    {
        char op[3];
        int l,r,d;
        scanf("%s%d%d",op,&l,&r);
        if (op[0]=='C')
        {
            scanf("%d",&d);
            change(l,r,d);
        }
        else
            printf("%lld\n",ask(l,r));
    }
}
