#include<iostream>
using namespace std;
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
    int y,m,d,k,y1,m1,d1;
    scanf("%d%d%d%d",&y,&m,&d,&k);
    if((y%4==0&&y%100!=0||y%400==0))
       	a[2]++;
    for(int i=0;;m++,i++)
    {
    	if(k<=a[m]-d&&i==0)
    	{
    		printf("%d-%02d-%02d",y,m,d+k);
    		return 0;
		}
        if(k-a[m]>=0)
        	i==0?k-=(a[m]-d):k-=a[m];
        else 
        {
            d=k;
            break;
        }
        if(m==12)
        {
            m=0;
            y++;
			if((y%4==0&&y%100!=0||y%400==0))
       				a[2]==28?a[2]++:y;
       			else
       				a[2]==29?a[2]--:y;
        }
    }
    printf("%d-%02d-%02d\n",y,m,d);
    return 0;
}
