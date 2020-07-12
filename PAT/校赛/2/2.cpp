#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxn 1e6+10
using namespace std;
int n,m,k;
int a[1000010];
struct node{
	long long addmark=0,sum;//addmark延迟标记，sum区间和 
}mem[1000010];
void build(int root,int istart,int iend){//建树 
	if(istart==iend){
		mem[root].sum=a[istart];
		return;
	}
	int mid=(istart+iend)/2;
	build(root*2,istart,mid);
	build(root*2+1,mid+1,iend);
	mem[root].sum=mem[2*root].sum+mem[2*root+1].sum;	
}
void pushdown(int root,int len){//下放标记 
	if(mem[root].addmark!=0){
		mem[2*root].sum+=mem[root].addmark*(len-len/2);//下放标记时同时求和 
		mem[2*root].addmark+=mem[root].addmark;
		mem[2*root+1].sum+=mem[root].addmark*(len/2);
		mem[2*root+1].addmark+=mem[root].addmark;
		mem[root].addmark=0;//消除父节点的标记 
	}
}
void update(int root,int istart,int iend,int l,int r,int value){// 修改区间 
	if(r<istart||l>iend)
		return;
	if(l<=istart&&r>=iend){
		mem[root].addmark+=value;
		mem[root].sum+=value*(iend-istart+1);
		return;
	}
	pushdown(root,iend-istart+1);
	int mid=(istart+iend)/2;
	update(root*2,istart,mid,l,r,value);
	update(root*2+1,mid+1,iend,l,r,value);
	mem[root].sum=mem[root*2].sum+mem[root*2+1].sum;
}
long long query(int root,int istart,int iend,int l,int r){//查询区间 
	if(iend<l||istart>r)
		return 0;
	if(istart>=l&&iend<=r){
		return mem[root].sum;
	}
	pushdown(root,iend-istart+1);
	int mid=(istart+iend)/2;
	return query(root*2,istart,mid,l,r)+query(root*2+1,mid+1,iend,l,r);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	for(int i=1;i<=m;i++){
		int q,l,r;
		scanf("%d%d%d",&q,&l,&r);
		if(q==1){
			scanf("%d",&k);
			update(1,1,n,l,r,k);
		}
		else{
			printf("%lld\n",query(1,1,n,l,r));
		}
	}
	return 0;
}
