#include<bits/stdc++.h> 

using namespace std;
string str,max1,ss; 
int l=0,flag=0;
int main()
{
	getline(cin,str);
	l=str.size();
	max1="";
	for(int i=0,j=i;i<l&&j<l;j++)
	{
		
		if(str[j]==' ')
		{	
			flag=1;
			if(max1.size()<str.substr(i,j-i).size())	
			{
				max1=str.substr(i,j-i);
			}
			i=j+1;
			j=i;	
		}
		if(j==l-1&&flag)
		{
			ss=str.substr(i,j);
			if(max1.size()<ss.size())	
			{
				max1=ss;
			}
		}
	}
	if(flag)
	{
		cout<<max1<<endl;
	}
	else
	{
		cout<<str<<endl;
	}
	return 0;
}
