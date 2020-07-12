#include <stdio.h>
int main()
{
    int a[1500],z=0,M=0,n,i;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    for(int i=0; i<n-1; i++)
        if(a[i+1]==a[i]+1)
        {
            z++;
            if(a[i+1]==1000)
                z++;
            if(a[i] == 1)
                z++;
            M=M>z?M:z;
        }
        else
            z=0;
    printf("%d\n",M-1);
}
