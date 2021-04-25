#include<bits/stdc++.h>

#define ll long long
using namespace std;
 
vector<char> vt1;
vector<char> vt2;
string s1,s2;
bool E(int l,int r)
{
	for(int i=l;i<=r;i++)
	{
		if(s1[i]!=s2[i])
		{
			return false;
		}
	}
	return true;
}
bool NE(int l,int r)
{
	for(int i=l;i<=r;i++)
	{
//		if(!((s1[i]=='0'&&s2[i]=='1')||(s1[i]=='1'&&s2[i]=='0')))
		if ((s1[i] == s2[i]))
		{
			return false;
		}
	}
	return true;
}
int main()
{


	int t;
	cin>>t;
	while(t--)
	{
		
		int n;
		cin>>n;
		cin>>s1;
		cin>>s2;
		int flag=0;
		int l,r;
		int index=0;
		l=r=0;
		for(int i=0;i<n;i++)
		{
			if(s2[i]=='1')
			{
				flag++;
			}
			else{
			flag--;
			}
			if(flag==0)
			{
				r=i;
				if(!(E(l,r)||NE(l,r)))
				{
					index=-1;
					break;
				}
				l=r+1;
			}
		}
		r=n;
		if(flag!=0&&!E(l,r))
		{
			index=-1;
		}
		if(index==-1)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
		}
	}
	return 0;
 }
