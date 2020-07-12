#include<bits/stdc++.h> 

using namespace std;
string s1,s2,s3;
int main()

{
	int n;
	scanf("%d",&n);
	if(n==0)
	{
		puts("0");
		return 0;
	}
	s1="1",s2="01";
	if(n==1)
	{
		puts("1");
		return 0;
	}
	if(n==2)
	{
		puts("01");
		return 0;
	}
	for(int i=2;i<n;i++)
	{
		s3=s1+s2;
		s1=s2;
		s2=s3;
	}
	cout<<s3<<endl;
	return 0;

}
