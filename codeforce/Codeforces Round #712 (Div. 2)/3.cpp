#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<char> vt1;
vector<char> vt2;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		vt1.clear();
		vt2.clear();
		int flag1,flag2;
		flag1=flag2=0;
		int n;
		cin>>n;
		string s;
		cin>>s;
		int flag=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='1')
			{
				if(flag1==0||flag2==0)
				{
					flag1++;
					flag2++;
					vt1.push_back('(');
					vt2.push_back('(');
				}
				else
				{
					flag1--;
					flag2--;
					vt1.push_back(')');
					vt2.push_back(')');
				}
			}
			else
			{
				if(flag1==0)
				{
					flag1++;
					flag2--;
					vt1.push_back('(');
					vt2.push_back(')');
				}
				else if(flag2==0)
				{
					flag1--;
					flag2++;
					vt1.push_back(')');
					vt2.push_back('(');
				}
				else
				{
					flag1++;
					flag2--;
					vt1.push_back('(');
					vt2.push_back(')');
				}
			}
			if(flag1<0||flag2<0)
			{
				break;
			}
		}
		if(flag1==0&&flag2==0)
		{
			cout<<"YES"<<endl;
			for(int i=0;i<vt1.size();i++)
			{
				cout<<vt1[i];
			}
			cout<<endl;
			for(int i=0;i<vt2.size();i++)
			{
				cout<<vt2[i];
			}
			cout<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
		
	}
	return 0;
 }
