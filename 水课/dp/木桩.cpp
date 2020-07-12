#include <iostream>
#include <algorithm>
using namespace std;
int a[1005],dp[1005];
//int mupper_bound(int *a,int *b, int x)
//{
//	int l = 0,r = (b - a) - 1;
//	while(l <= r)
//	{
//		int mid = (l + r) / 2;
//		if(*(a + mid) > x)
//		{
//			
//		}
//		else
//		{
//			
//		}
//	}
//}
int main()
{
    int n, asn = 0;
    cin >> n;
	for (int i = 1; i <= n; i++)
        cin >> a[i];
    int len = 1;
    dp[1] = a[1];
    for (int i = 2; i <= n; i++)
    {

        if(dp[len] >= a[i] )
        {
            dp[++len] = a[i];
        }
        else
        {
            int j = upper_bound(dp + 1, dp + n + 1, a[i], greater<int>()) - dp;//第一个小于等于
            dp[j] = a[i];
        }
    }
//    for (int i = 1; i <= len; i++)cout << dp[i] << endl;
    cout << len << endl;
    return 0;
}
