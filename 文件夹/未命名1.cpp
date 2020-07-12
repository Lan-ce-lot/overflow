#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int n;
    while(1)
    {
		scanf("%d",&n);
		if(n==0)
		{
			break;
		}
        double x[100],y[100],sum=0;
        int  i;
        for(i=0;i<n;i++)
        {
            scanf("%lf %lf",&x[i],&y[i]);
        }
        for(i=1;i<n-1;i++)
        {
           /* double temp=x[0]*y[i]-x[i]*y[0]+x[i]*y[i+1]-x[i+1]*y[i]+x[i+1]*y[0]-x[0]*y[i+1];*/
            sum=sum+(x[0]*y[i]-x[i]*y[0]+x[i]*y[i+1]-x[i+1]*y[i]+x[i+1]*y[0]-x[0]*y[i+1])/2;
        }
        printf("%.1lf\n",sum);
    }
    return 0;
}

