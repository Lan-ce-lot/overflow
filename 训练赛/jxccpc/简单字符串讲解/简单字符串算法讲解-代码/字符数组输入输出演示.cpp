#include <bits/stdc++.h>
using namespace std;
int main()
{
    char s[110];
    char ch;
    int H, M, S;
    strcpy(s, "T:13:11:01");
    sscanf(s, "%c:%d:%d:%d", &ch, &H, &M, &S);

    printf("字符串s：%s\n", s);
    printf("%c %d %d %d\n", ch, H, M, S);

    sprintf(s, "%d%d%d", H, M, S);
    printf("新的字符串：%s\n", s);
    return 0;
}