#include <cstdio>
#include <algorithm>
using namespace std;
char s[200010];
int sum[130][200010];
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", s + 1);
    for(int i = 1; i <= n; i ++){
        for(int j = '0'; j <= '1'; j ++){
            sum[j][i] = sum[j][i - 1] + (s[i] == j);
        }
    }
    int l = 1, r = 1;
    int num1, num0;
    int ans = 0;
    while(r < n && l <= r){
        r ++;
        num1 = sum['1'][r] - sum['1'][l - 1];
        num0 = sum['0'][r] - sum['0'][l - 1];
        if(num1 <= k || num0 <= k){
            //printf("xss %d %d\n", l, r);
            ans = max(ans, r - l + 1);
        }
        else{
            l ++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
