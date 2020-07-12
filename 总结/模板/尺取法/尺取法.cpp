#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 1e6*2+10;
int a[MAX];
int x,w;
int ans;
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n;i++){
		scanf("%d",&x);
		w+=x;
		a[i]=min(a[i-1],w);
		if(w>0){//总和大于0，特判
			ans=max(ans,i);//不需要减1
			continue;
		}
//		int l=1,r=i;
//		while(l<=r){//二分找左边最小值
//			int mid=(l+r)>>1;
//			if(a[mid]<w) r=mid-1;
//			else l=mid+1;
//		}
		int temp=i-(lower_bound(a+1,a+i,w,greater<int>())-a);
		ans=max(ans,temp);
//		ans=max(ans,i-r-1);//需要减1，自己推一下，不好解释~~（大体就是找到右边小于0的那一块，多了一个负值，把多的那个值去掉，右边就是大于0的，当然那个负值在右边那一块的最左边）
	}
	printf("%d\n",ans);
	return 0;
}
