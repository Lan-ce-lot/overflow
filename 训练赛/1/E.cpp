/*�߶���ά������ͣ�ԭ��Ŀ�����3372���˴����AC��*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define ll long long
const int INF=0x3f3f3f3f;
struct node//�Խṹ�����ʽ�洢�߶���
{
    long long tree,treeA,treeX,treeR,left,right;
}a[400003];
long long n,m,l,k,r,x,y,findA=INF,findO=0,findX=0,srx,add,i,j,q;

void make(ll l,ll r,ll k)//����һ���߶���
{
    ll mid;
    a[k].left=l,a[k].right=r;//���߶���ÿһ���ڵ��ʾ�����������ٽ��Ǻ�
    if (l==r)
    {//������ٽ�������ٽ磬˵�����Խ��ж����ˣ��������ֻ��һ��ֵ
        scanf("%lld",&a[k].tree);
        return;
    }//��ô�������ֵ�������ֻ��һ�������������Ҫֵ
    mid=(l+r)/2;//����ѵ�ǰ�����۰�
    make(l,mid,k*2);//������������������
    make(mid+1,r,k*2+1);//������������������
    a[k].treeA=(a[k*2].treeA&a[k*2+1].treeA);
    a[k].treeO=(a[k*2].treeO|a[k*2+1].treeO);
    a[k].treeX=(a[k*2].treeA^a[k*2+1].treeX);
    //��Ϊ����ά����������ͣ�����ֱ�Ӱ����Ҷ��ӵ�ֵ���������Ǹ��׽ڵ��ֵ
    return;
}


void look(int k)//�������
{
    ll mid;
    if (a[k].left>=x&&a[k].right<=y)
    {//�����������ȫ�����������������ڣ���get�������ֵ
        findA&=a[k].treeA;
        findO|=a[k].treeO;
        findX^=a[k].treeX;
        return;
    }
    mid=(a[k].left+a[k].right)/2;//���˽ڵ��ʾ����������
    if (x<=mid) look(k*2);//������Ҿ���
    if (y>mid) look(k*2+1);//�ұ����Ҿ���
    return;
}

int main()
{
    scanf("%d%d",&n,&m);//�����ʼ�߶γ��ȺͲ�������
    make(1,n,1);//�����߶������߶δ�1��ʼ����n���������ڵ���1��
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
    
//    for (i=1;i<=m;i++)//ִ��ÿһ������
//    {
//        scanf("%lld%lld%lld",&srx,&x,&y);
//        find=0;
//        if (srx==1)//SRX��1������������Ϣ
//        {
//            scanf("%lld",&add);
//            change(1);//�������Ҫ��1��ʼ
//        }
//        if (srx==2)//SRX��2����ѯ������Ϣ
//        {
//            look(1);//�������һ���Ĵ�1��ʼ
//            printf("%lld\n",find);
//        }
//    }
    return 0;
}

