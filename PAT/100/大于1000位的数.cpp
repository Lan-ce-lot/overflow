#include<cstdio> 
#include<cstring>
int main()
{   
    char n[1010];
    scanf("%s",n);
    int len = strlen(n);
    int cnt[10] = {0};
    for(int i = 0;i < len;i ++) {
        cnt[n[i]-48]++;//这里可以写成cnt[n[i]-'0']++;
    }
    for(int i = 0;i < 10;i++) {
        if(cnt[i] != 0) printf("%d:%d\n",i,cnt[i]);
    }

    return 0;
 } 

