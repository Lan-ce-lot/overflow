#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,k,a,m=99999999999,s=0;
	cin>>n>>k;
	for(long long int i=0;i<n;i++)
	{
		cin>>a;
		m=min(m,a);
		s+=a;
	}
	s<k?cout<<-1:cout<<min(m,(s-k)/n);
}
