#include<iostream>
using namespace std;
typedef long long ll;
const long long mod = 1e9+7;
ll a[100000];
#define  MAX 1000
void  Mul(int n)
{
    int i=0,j=0;
    int s;//�˻�
    int c=0;//��λ
    //��Ŵ�����a
    int arr[MAX]={0};
    arr[0]=1;

    for(i=2;i<=n;i++)
    {
        for(j=0;j<MAX;j++)
        {

            s=arr[j]*i+c;
            arr[j]=s%10;
            c=s/10;//��λ
        }
    }

    for(i=MAX-1;i>=0;i--)
    {
        //��������0����ʼ���
        if(arr[i])
            break;
    }
    for(j=i;j>=0;j--)
    {
        //�������
        printf("%d",arr[j]);
    }

    printf("\n");
}

void Test()
{

    Mul(1);
    Mul(10);
    Mul(100);
}
long long func(int x){
	for(int i=0;i<x;i++)
	{
		
	}
    if (x==1||x==0){
        return 1;
    }
    return (x*func(x-1)+(x-1)*func(x-2))%mod;
}

int n;
int main(){

    cin>>n;
    cout<<a[n];
    return 0;
}

