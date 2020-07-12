#include<bits/stdc++.h> 

using namespace std;
int a[10005],b[10005];
struct l{
	int x1,y1,w1;
};

bool cmp1(l a,l b)
{
	if(a.x1==b.x1)
	return 	a.y1<b.y1;
	return a.x1<b.x1;
}
bool cmp2(l a,l b)
{
	if(a.y1==b.y1)
	return 	a.x1<b.x1;
	return a.y1<b.y1;
}
int main()

{
	int x,y,q,step=0,go=0,go1=0;
	scanf("%d%d%d",&x,&y,&q);
	l zz[q];
	for(int i=0;i<q;i++)
	{
		scanf("%d%d%d",&zz[i].x1,&zz[i].y1,&zz[i].w1);
	}
	sort(zz,zz+q,cmp1);
	go+=zz[0].w1;
	int tempy=zz[0].y1;
	for(int i=0;i<q;i++)
	{
		
		if(tempy<=zz[i+1].y1)
		{
			tempy=zz[i+1].y1;
			go+=zz[i+1].w1;
		}
	}
	sort(zz,zz+q,cmp2);
	go1+=zz[0].w1;
	int tempx=zz[0].x1;
	for(int i=0;i<q;i++)
	{
		
		if(tempx<=zz[i+1].x1)
		{
			tempx=zz[i+1].x1;
			go1+=zz[i+1].w1;
			
		}	
	}
	step=2*x-1-1;
	printf("%d %d\n",step,go);
	return 0;

}
