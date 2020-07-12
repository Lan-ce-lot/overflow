#include <bits/stdc++.h>
using namespace std;
int main()
{
    char a[10], b[10];
    int i, s1 = 0, s2 = 0, na, nb;
    scanf("%s %[^\n]", a, b);
    na = strlen(a);
    nb = strlen(b);
    //cout<<a<<"+"<<b<<endl;
    for(i = 0; i < na; i++)
    {
        if(a[i] < 48 || a[i] > 57)
        {
            s1 = 1;
            break;
        }
        if(a[0] == '+')s1--;
        if(atoi(a) < 1 || atoi(a) > 1000)s1++;
    }
    for(i = 0; i < nb; i++)
    {
        if(b[i] < 48 || b[i] > 57)
        {
            s2 = 1;
            break;
        }
        if(b[0] == '+')s2--;
        if(atoi(b) < 1 || atoi(b) > 1000)s2++;
    }
    if(s1 >= 1 && s2 >= 1)
        printf("? + ? = ?\n");
    if(s1 >= 1 && s2 == 0)
        printf("? + %d = ?\n", atoi(b));
    if(s1 == 0 && s2 >= 1)
        printf("%d + ? = ?\n", atoi(a));
    if(s1 == 0 && s2 == 0)
    {
        printf("%d + %d = %d\n", atoi(a), atoi(b), atoi(a) + atoi(b));
    }
}
