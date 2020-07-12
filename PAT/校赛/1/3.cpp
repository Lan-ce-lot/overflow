#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define ll long long
struct node//�Խṹ�����ʽ�洢�߶���
{
    long long tree,left,right,lazy;
}a[800003];//�߶���ά����ֵ���߶���ˣ��߶��Ҷˣ�lazy���
long long n,m,l,k,r,x,y,find,srx,add,i,j;

void make(ll l,ll r,ll k);//�����߶���
void SUC(ll k);//����ǰ�ڵ��lazy���
void change(int k);//�������
void look(int k);//�����ѯ
int main()
{
    scanf("%lld%lld",&n,&m);//�����ʼ�߶γ��ȺͲ�������
    make(1,n,1);//�����߶������߶δ�1��ʼ����n���������ڵ���1��
    for (i=1;i<=m;i++)//ִ��ÿһ������
    {
        scanf("%lld%lld",&x,&y);
        find=0;

            look(1);//�������һ���Ĵ�1��ʼ
            printf("%lld\n",find/(y-x+1));
    }
    return 0;
}


void make(ll l,ll r,ll k)//����һ���߶���
{
    ll mid;
    a[k].lazy=0;
    //�����ʱ���lazyֵ���Ϊ0������ֻ�мӼ�������ֻ��һ��lazy���
    a[k].left=l,a[k].right=r;//���߶���ÿһ���ڵ��ʾ�����������ٽ��Ǻ�
    if (l==r)
    {//������ٽ�������ٽ磬˵�����Խ��ж����ˣ��������ֻ��һ��ֵ
        scanf("%lld",&a[k].tree);
        return;
    }//��ô�������ֵ�������ֻ��һ�������������Ҫֵ
    mid=(l+r)/2;//����ѵ�ǰ�����۰�
    make(l,mid,k*2);//������������������
    make(mid+1,r,k*2+1);//������������������
    a[k].tree=a[k*2].tree+a[k*2+1].tree;
    //��Ϊ����ά����������ͣ�����ֱ�Ӱ����Ҷ��ӵ�ֵ���������Ǹ��׽ڵ��ֵ
    return;
}

void SUC(ll k)//����lazy��ǣ�k�ǵ�ǰ�ڵ���±�
{//ֻ��lazy���!=0��ʱ��Ż�ִ��
    ll l,r;
    l=k*2,r=k*2+1;//ȡ����ǰ�ڵ�����Ҷ���
    a[l].lazy+=a[k].lazy;//�ѵ�ǰ�ڵ��lazyֵ���ݸ����Ҷ���
    a[r].lazy+=a[k].lazy;
    //��Ϊ����ֻ�мӼ�������lazyֵ������+=�ķ�ʽ���ݸ����Ҷ���
    //���Ϊ���Ҷ��Ӹ����ˣ��������Ҷ��ӵĶ��ӻ�û����
    a[l].tree+=a[k].lazy*(a[l].right-a[l].left+1);
    a[r].tree+=a[k].lazy*(a[r].right-a[r].left+1);
    //�������Ҷ��ӵ�ֵ
    a[k].lazy=0;//���ѵ�ǰ�ڵ��lazyֵ��ʼ��
    return;
}

void look(int k)//�������
{
    ll mid;
    if (a[k].left>=x&&a[k].right<=y)
    {//�����������ȫ�����������������ڣ���get�������ֵ
        find+=a[k].tree;
        return;
    }
    //���������ȡֵ���������ִ˽ڵ���lazy��ǣ��͸������Ķ��ӽڵ�
    if (a[k].lazy>0) SUC(k);
    mid=(a[k].left+a[k].right)/2;//���˽ڵ��ʾ����������
    if (x<=mid) look(k*2);//������Ҿ���
    if (y>mid) look(k*2+1);//�ұ����Ҿ���
    return;
}

