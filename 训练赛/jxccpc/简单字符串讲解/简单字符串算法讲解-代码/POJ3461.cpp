#include <iostream>
#include <cstring>
using namespace std;
typedef unsigned long long ull;
const int maxn = 1e6+10;
const int p = 13333331;
ull Hash[maxn], power[maxn];
char w[maxn], t[maxn];
int T;
void init()
{
    power[0] = 1;
    for(int i = 1; i < maxn; i++)
        power[i] = power[i-1]*p;
}
int main()
{
   // freopen("/Users/zhangkanqi/Desktop/11.txt","r",stdin);
    init();
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", w+1);
        scanf("%s", t+1);
        ull hash = 0, HASH;
        int ans = 0;
        int len1 = strlen(w+1), len2 = strlen(t+1);
        for(int i = 1; i <= len1; i++)
            hash = hash*p + w[i]-'A'+1;
        for(int i = 1; i <= len2; i++)
            Hash[i] = Hash[i-1]*p + t[i]-'A'+1;
        for(int i = len1; i <= len2; i++)
        {
            HASH = Hash[i]-Hash[i-len1]*power[len1];
            if(HASH == hash) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}

