#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
#include<vector> 
using namespace std;
typedef long long ll;
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
int a[200005];
//int main()
//
//{
//	int n;
//	while(~scanf("%d",&n))
//	{
//		int flag=0;
//		int ans=0;
//		for(int i=0;i<sizeof(a);i++)
//			a[i]=0;
//			
//		for(int i=0;i<=n;i++)
//		{
//			scanf("%d",&a[i]);
//			
//		}
//		sort(a,a+n+1);
//		for(int i=n;i>=0;i--)
//		{
//			if(a[i]>=i+1)
//			{
//				printf("%d\n",a[i]);
//				flag=1;
//				break;
//			}
//			
//		}
//		flag==0?printf("%d\n",*min_element(a,a+n+1)):n;
//	}
//	
//
////	system("pause");
//	return 0;
//
//}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
 
        for(int i=0;i<=n;i++){
            scanf("%d",&a[i]);
        }
        int s=0;
        for(int i=n;i>=0;i--){
            s=s+a[i];
            if(s>=i){
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
