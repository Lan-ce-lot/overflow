#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
    int n;
	long long ans=0;
    while(scanf("%d",&n)&&n){
        int a[1000];
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        ans=0;
        sort(a,a+n);//�������в���һ��ɾ����Ľ��
//f(n)=(n-1) {f(n-1)+f(n-2)}
//���ǵ��ƹ�ʽ����n��1��2��3��4��5���������ܽ����Ħ�����⡣
//f(1)=0 f(2)=1 f(3)=2 f(4)=9 f(5)=44
        do{
        	int flag=0;
        	for(int i=0;i<n;i++)
				if(a[i]==i+1)
            	{
            		flag=1;
            		break;
				}

			if(flag)continue;

            for(int i=0;i<n;i++)
            {
            	for(int j=i+1;j<n;j++)
            	{
            		if(a[i]>a[j])
            		{
            			ans+=(a[i]-a[j])*(j-i);
					}

				}
//            	printf("%d ",a[i]);

			}

//            puts("");
        }while(next_permutation(a,a+n));
        printf("%lld\n",ans);
    }
    return 0;
}
