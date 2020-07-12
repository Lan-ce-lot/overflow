#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double max_1, temp, temp2, cnt = 1.000000, max_2;
double num[10005];
int main()
{
    int T, n;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%lf", &num[i]);
        sort(num, num + n);
        max_2 = num[n - 1];
        if(max_2 < 0.500000)
        {
            max_1 = num[n - 1];
            temp2 = cnt;
            for(int i = n - 2; i >= 0; i--)
            {
                temp2 *= (cnt - num[i + 1]);
                max_1 *= (cnt - num[i]);
                max_1 += num[i] * temp2;
                max_2 = max(max_1, max_2);
            }
        }
        printf("%.12lf\n", max_2);
    }
}
