#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 1e6*2+10;
ll a[MAX];
ll x,w;
int ans;
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n;i++){
		scanf("%lld",&x);
		w+=x;
		a[i]=min(a[i-1],w);
		if(w>0){//�ܺʹ���0������
			ans=max(ans,i);//����Ҫ��1
			continue;
		}
		int l=1,r=i;
		while(l<=r){//�����������Сֵ
			int mid=(l+r)>>1;
			if(a[mid]<w) r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-r-1);//��Ҫ��1���Լ���һ�£����ý���~~����������ҵ��ұ�С��0����һ�飬����һ����ֵ���Ѷ���Ǹ�ֵȥ�����ұ߾��Ǵ���0�ģ���Ȼ�Ǹ���ֵ���ұ���һ�������ߣ�
	}
	printf("%lld\n",ans);
	return 0;
}
