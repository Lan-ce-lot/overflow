#include<bits/stdc++.h> 

using namespace std;
string str,max1;
int flag=0;
int main()

{
	getline(cin,str);
	int l=str.size();
	max1="";
	for(int i=0,j=0;i<l,j<l;)
	{
		if(str[j]==' ')
		{
			flag=1;
			cout<<i<<j;
			cout<<str.substr(i,j)<<endl;
			j-i>max1.size()?max1=str.substr(i,j):max1;
			i=j+1;
			j=i;
		}
		j++;
	}
	flag?cout<<max1<<endl:cout<<str<<endl;
	return 0;

}
