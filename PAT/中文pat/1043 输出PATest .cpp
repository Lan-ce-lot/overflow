#include<bits/stdc++.h>
using namespace std;
string str;
int a[50];
int main()
{//PATest
	cin>>str;
	for(int i=0;i<str.size();i++)
	{
		a[str[i]]++;
		
	}
	for(int i=0;;i++)
	{
		if(a['P'])
		{
			cout<<'P';
			a['P']--;
		}
		if(a['A'])
		{
			cout<<'A';
			a['A']--;			
		}
		if(a['T'])
		{
			cout<<'T';
			a['T']--;			
		}
		if(a['e'])
		{
			cout<<'e';
			a['e']--;			
		}
		if(a['s'])
		{
			cout<<'s';
			a['s']--;			
		}
		if(a['t'])
		{
			cout<<'t';
			a['t']--;			
		}				
		if(!(a['P']||a['A']||a['T']||a['e']||a['s']||a['t']))
			break;
	 } 
	 puts("");
			
		
	return 0;
}
