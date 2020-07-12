#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=1-n;i<n;i++){
    for(j=0;j<n-1-fabs(i);j++)
    printf(" ");
    for(j=0;j<n;j++)
    printf("*");
    if(i<n-1)
    printf("\n");
    }
    return 0;
 }
