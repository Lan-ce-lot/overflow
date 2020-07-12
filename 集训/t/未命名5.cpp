#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char s[1001];
int a[27];
int main()
{
    int i,m,n,sum=0,max;
    scanf("%s %d",s,&n);
    for(i=0;i<26;i++)
    scanf("%d",&a[i]);
    m=strlen(s);
    for(i=0;i<m;i++)
    sum+=(i+1)*a[s[i]-'a'];
   
    max=*max_element(a,a+26);
    i=m+1;
    while(n--)
    {
       sum+=i*max;
       i++;
    }
    printf("%d\n",sum);
    return 0;
}

