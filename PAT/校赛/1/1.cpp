#include<bits/stdc++.h> 
using namespace std;
const int INF=0x3f3f3f3f;
#define N 1000000
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
typedef long long ll; 
struct node
{
    int tree,left,right,lazy;
}a[4000003];
int find1,t,n,x,y;
void make(ll l,ll r,ll k)
{
    ll mid;
    a[k].lazy=0;
    a[k].left=l,a[k].right=r;
    if (l==r)
    {
        scanf("%d",&a[k].tree);
        return;
    }
    mid=(l+r)/2;
    make(l,mid,k*2);
    make(mid+1,r,k*2+1);
    a[k].tree=a[k*2].tree+a[k*2+1].tree;
    return;
}
void SUC(ll k)
{
    ll l,r;
    l=k*2,r=k*2+1;
    a[l].lazy+=a[k].lazy;
    a[r].lazy+=a[k].lazy;
    a[l].tree+=a[k].lazy*(a[l].right-a[l].left+1);
    a[r].tree+=a[k].lazy*(a[r].right-a[r].left+1);
    a[k].lazy=0;
    return;
}
void aver(int k)
{
    ll mid;
    if (a[k].left>=x&&a[k].right<=y)
    {
        find1+=a[k].tree;
        return;
    }
    if (a[k].lazy>0) SUC(k);
    mid=(a[k].left+a[k].right)/2;
    if (x<=mid) aver(k*2);
    if (y>mid) aver(k*2+1);
    return;

}
int main()
{
    scanf("%d%d",&t,&n);
    make(1,t,1);
    for(int i=0;i<n;i++)
    {
        find1=0;
        scanf("%d%d",&x,&y);
        aver(1);
        cout<<find1/(y-x+1)<<endl;
    }
    return 0;
}
