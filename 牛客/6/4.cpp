#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m;
	
	while(cin>>n>>m)
	{
		long long x=m-(n-6*m);
	    if(x>=0&&x<=m)
	    cout<<x<<endl;
        else if(x<0&&n<=9*m)
            cout<<0<<endl;
        else
	    cout<<"jgzjgzjgz\n";
	}
}

