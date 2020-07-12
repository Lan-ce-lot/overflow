#include <stdio.h>
#include <stdlib.h>
struct student
{
    char name[10];
    char num[10];
    int score;
} st[100];
int main()
{

    int n, i, max = 0, min = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%s %s %d", st[i].name, st[i].num, &st[i].score);
        if(st[i].score > st[max].score)
            max = i;
        if(st[i].score < st[min].score)
            min = i;
    }
    printf("%s %s\n", st[max].name, st[max].num);
    printf("%s %s\n", st[min].name, st[min].num);
    return 0;
}
