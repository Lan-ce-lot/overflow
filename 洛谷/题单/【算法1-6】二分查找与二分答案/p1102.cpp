//��ʵֱ�Ӷ��־ͺ���
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,t,n,i,l,r,mid,w,q,a[5000000];
int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a + 1, a + n + 1);
    for(i=1;i<=n;i++)
    {
        l=i+1;r=n;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(a[i]+m<=a[mid])
              r=mid-1;
            else
              l=mid+1;
        }
        w=l;//�ҳ�������ָ���������ĵ�һλ
        l=i+1;r=n;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(a[i]+m<a[mid])
              r=mid-1;
            else
              l=mid+1;
        }
        q=l;//�ҳ�������ָ����������ĩλ+1
        t+=q-w;//ֱ�Ӽ����������ĳ���
    }
    printf("%lld",t);
    return 0;
}
