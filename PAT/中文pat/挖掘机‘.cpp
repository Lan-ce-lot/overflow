#include <iostream>
#include <algorithm>
#include <vector>
#include<cstring>
using namespace std;
string s1,s2,ans="";
int a[200];
int main()
{
   getline(cin,s1);

   getline(cin,s2);
   for(int i=0;i<s1.size();i++)
   {
   		if(s1[i]>='A'&&s1[i]<='Z')
   		{
   			a[s1[i]-0]++;
			a[s1[i]-0+32]++;
		   }
		if(s1[i]>='a'&&s1[i]<='z')
		{
			a[s1[i]-0]++;
			a[s1[i]-0-32]++;
		}
   		else
   		{
   			a[s1[i]-0]++;	
		}
   }
   if(s1.find('+') != string::npos)
   {
   		for(int i=0;i<s2.size();i++)
		{
			if(s2[i]>='A'&&s2[i]<='Z')
			continue;
			a[s2[i]-0]==0?ans+=s2[i]:ans;
		  }
		cout<<ans<<endl;
   }
   
   else
   {
   		for(int i=0;i<s2.size();i++)
		{
			a[s2[i]-0]==0?ans+=s2[i]:ans;
		  }	
		cout<<ans<<endl;
   }
    return 0;
}
