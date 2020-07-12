/*线段树维护区间和，原题目：洛谷3372（此代码可AC）*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define ll long long
const int INF=0x3f3f3f3f;
struct node//以结构体的形式存储线段树
{
    long long tree,treeA,treeX,treeR,left,right;
}a[400003];
long long n,m,l,k,r,x,y,findA=INF,findO=0,findX=0,srx,add,i,j,q;

void make(ll l,ll r,ll k)//构造一棵线段树
{
    ll mid;
    a[k].left=l,a[k].right=r;//把线段树每一个节点表示的区间左右临界标记好
    if (l==r)
    {//如果左临界等于右临界，说明可以进行读入了，这个区间只有一个值
        scanf("%lld",&a[k].tree);
        return;
    }//那么所读入的值就是这个只有一个数的区间的重要值
    mid=(l+r)/2;//否则把当前区间折半
    make(l,mid,k*2);//构建这段区间的左子树
    make(mid+1,r,k*2+1);//构建这段区间的右子树
    a[k].treeA=(a[k*2].treeA&a[k*2+1].treeA);
    a[k].treeO=(a[k*2].treeO|a[k*2+1].treeO);
    a[k].treeX=(a[k*2].treeA^a[k*2+1].treeX);
    //因为这里维护的是区间和，所以直接把左右儿子的值加起来就是父亲节点的值
    return;
}


void look(int k)//区间查找
{
    ll mid;
    if (a[k].left>=x&&a[k].right<=y)
    {//如果此区间完全包含在所查找区间内，就get此区间的值
        findA&=a[k].treeA;
        findO|=a[k].treeO;
        findX^=a[k].treeX;
        return;
    }
    mid=(a[k].left+a[k].right)/2;//将此节点表示的区间折中
    if (x<=mid) look(k*2);//左边能找就找
    if (y>mid) look(k*2+1);//右边能找就找
    return;
}

int main()
{
    scanf("%d%d",&n,&m);//输入初始线段长度和操作次数
    make(1,n,1);//构造线段树（线段从1开始，到n结束，根节点是1）
    for(int i=0;i<m;i++)
    {
    	find=0;
    	scanf("%d",&q);
    	if(q==1)
    	{
    		x=2,y=n;
    		look(1);
    		printf("%d\n",)
		}
		if(q==n)
		{
			x=1,y=n-1;
			look(1);
		}
    	find=0;
    	
    	look(1);
    	
		
	}
    
//    for (i=1;i<=m;i++)//执行每一步操作
//    {
//        scanf("%lld%lld%lld",&srx,&x,&y);
//        find=0;
//        if (srx==1)//SRX是1：更新区间信息
//        {
//            scanf("%lld",&add);
//            change(1);//区间更新要从1开始
//        }
//        if (srx==2)//SRX是2：查询区间信息
//        {
//            look(1);//区间查找一样的从1开始
//            printf("%lld\n",find);
//        }
//    }
    return 0;
}

