#include <iostream>
#include<algorithm>
using namespace std;
#define ll long long 

int main()
{
	int n=0;
	while(cin>>n)
	{
		int ans=20;
    for(int i=0;i<n;i++)
    {
    	int t=100;
    	ans=ans*8+(t+20);
    	t*=10;
	}
	cout<<ans;
	}
	
    return 0;
}
//14096602
