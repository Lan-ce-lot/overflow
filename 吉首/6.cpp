
#include<iostream>
using namespace std;
#define MAX 500000
bool a[MAX];
int cnt;
int plist[10000],pcount=0;
int prime(int n)
{
	int i;
	if((n!=2 && !(n%2)) || (n!=3 && !(n%3)) || (n!=5 && !(n%5)) || (n!=7 && !(n%7)))
		return 0;
	for(i=0;plist[i]*plist[i]<=n;++i)
		if(!(n%plist[i]))
			return 0;
	return n>1;
}
void initprime()
{
	int i;
	for(plist[pcount++]=2,i=3;i<50000;++i)
		if(prime(i))
			plist[pcount++]=i;
}
int Div( int m )   //这段代码是核心，估计需要的是公式规律，还没琢磨透（来源于网络）
{
    int tmp,ret=1;
    for( int i=0; plist[i]*plist[i]<=m ; i++ )
    {
        if( m % plist[i] == 0 )
        {
            tmp = 0;
            while( m % plist[i] == 0 )
            {
                tmp ++;
                m /= plist[i];
            }
            ret = ret * ( tmp+1 );
        }
    }
    if( m != 1 )
        ret = ret * 2;
    return ret;
}
 
int main( )
{
    int n,t;
    int max, ret;
    initprime( );
        cin>>n;
        max=1;t=1;
        for( int i=1; i<=n; i++ )
        {
            ret=Div(i);
            if( ret > max )
            {
                max = ret;t=i;
            }
        }
        cout<<max<<endl;
    return 0;
}
