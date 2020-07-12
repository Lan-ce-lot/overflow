#include <iostream>
#include <cstring>
using namespace std;
typedef unsigned long long ull;
const int maxn = 1e6+10;
const int p = 1333331;
ull Hash[maxn], power[maxn];
char s[maxn];
void init()
{
    power[0] = 1;
    for(int i = 1; i < maxn; i++)
        power[i] = power[i-1]*p;
}
int main()
{
    //freopen("/Users/zhangkanqi/Desktop/11.txt","r",stdin);
    init();
    while(scanf("%s", s+1))
    {
        if(strcmp(s+1, ".") == 0) break;
        int len = strlen(s+1);
        for(int i = 1; i <= len; i++)
            Hash[i] = Hash[i-1]*p + s[i]-'a'+1;
        for(int k = 1; k <= len; k++)
        {
            bool f = true;
            if(len%k) continue;
            ull hash = Hash[k];
            for(int i = 2*k; i <= len; i+=k)
            {
                if(hash != Hash[i]-Hash[i-k]*power[k])
                {
                    f = false;
                    break;
                }
            }
            if(f)
            {
                printf("%d\n", len/k);
                break;
            }
        }
    }
    return 0;
}