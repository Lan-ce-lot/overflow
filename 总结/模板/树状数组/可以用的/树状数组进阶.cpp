#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<bitset>
#include<string>
#include<cmath>
#include<sstream>
using namespace std;
typedef long long ll;
const double pi=acos(-1.0);
const int eps=1e-10;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn=500005;
int asum[maxn << 2],d1[maxn << 2],d2[maxn << 2],n,delta[maxn << 2];

int lowbit(int x)
{
	return x & -x;
}

void add (int *arr,int pos,int x)
{
	while(pos <= n)arr[pos] += x,pos += lowbit(pos);
}

void modify(int l,int r,int x)//Çø¼äÐÞ¸Ä
{
	add(d1,l,x),add(d1,r + 1,-x),add(d2,r + 1,-x * (r + 1));
}

ll getsum(int *arr,int pos)
{
	ll sum = 0;
	while(pos)sum += arr[pos],pos -= lowbit(pos);
	return sum;
}

ll query(int l,int r)
{
	return asum[r] + r * getsum(d1,r) - getsum(d2,r) - (asum[l - 1] + l * getsum(d1,l - 1) - getsum(d2,l - 1) );
}

int a[maxn],m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
        delta[i] = a[i] - a[i - 1];
        add(delta,i,delta[i]);
    }

    while(m--)
    {
        int index,x,y,k;
        scanf("%d",&index);
        if(index == 1)
        {
            scanf("%d%d",&x,&k);
            modify(x,x,k);
        }
        else
        {
            scanf("%d%d",&x,&y);
            printf("%d\n",query(x,y));
        }

    }

    return 0;
}
