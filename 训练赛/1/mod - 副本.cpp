#include<cstdio>
#include<iostream>
using namespace std;
const int	N=10e5;
long long n,q,yu,huo,yi,x,y,x2,y2;
struct node
{
	long long l,r,w,yu,huo,yi;//l��ʾ��ڵ㣬r��ʾ�ҽڵ㣬w��ʱ��ʾ����� 
}tree[4*N+1];//N�Ǳ�ʾ������� 
void build(int l,int r,int k)//�����߶��� 
{
	tree[k].l=l,tree[k].r=r;
	if(l==r)
	{
		scanf("%lld",&tree[k].w);
		tree[k].yu=tree[k].huo=tree[k].yi=tree[k].w;
		return;
	} 
	int m=(l+r)/2;
	build(l,m,k*2);
	build(m+1,r,k*2+1);
	tree[k].yu=tree[k*2].yu&tree[k*2+1].yu;
	tree[k].huo=tree[k*2].huo|tree[k*2+1].huo;
	tree[k].yi=tree[k*2].yi^tree[k*2+1].yi;//״̬�ϲ����˽���w=�������ӵ�w֮�� 
}

void sum(int k)//�����ѯ 
{
	if(tree[k].l>=x&&tree[k].r<=y)
	{
		yu&=tree[k].yu;
		huo|=tree[k].huo;
		yi^=tree[k].yi;
		return;
	}
	int m=(tree[k].l+tree[k].r)/2;
	if(x<=m) sum(k*2);
	if(y>m)  sum(k*2+1);
}

int main()
{
	int wa;
while(	cin>>n>>q)
{
		build(1,n,1);
	while(q--)
	{
		yu=0xffffffff;
		huo=yi=0;
		cin>>wa;
		 x=1,y=wa-1,x2=wa+1,y2=n;
		if(x<=y)
		sum(1);
		x=x2,y=y2;
		if(x<=y)
		sum(1);
		cout<<yu<<' '<<huo<<' '<<yi<<endl;
	}
}
}

