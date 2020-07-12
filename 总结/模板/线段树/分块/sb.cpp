#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,n,sum,i;
    scanf("%lld\n",&i);
    while(i--)
    {
        scanf("%lld\n",&n);
        sum=0;
        while(n--)
        {
            cin>>a;
            sum+=a;
            n--;
            printf("%lld\n",sum);
        }
    }
}
