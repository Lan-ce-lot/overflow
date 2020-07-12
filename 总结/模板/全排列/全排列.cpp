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
        sort(a,a+n);//可以自行测试一下删除后的结果
//f(n)=(n-1) {f(n-1)+f(n-2)}
//这是递推公式，令n＝1、2、3、4、5逐个推算就能解答蒙摩的问题。
//f(1)=0 f(2)=1 f(3)=2 f(4)=9 f(5)=44
        do{


            for(int i=0;i<n;i++)
            {
            	printf("%d ",a[i]);
			}
            ans++;
            puts("");
        }while(next_permutation(a,a+n));
        printf("%lld\n",ans);
    }

    return 0;
}
