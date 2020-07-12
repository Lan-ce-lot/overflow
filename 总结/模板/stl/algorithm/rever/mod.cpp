#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
	char a[1005];
	int t;
	cin>>t;
	getchar(); //∂¡»Îªª––
	while(t--)
	{
	gets(a);
    int len=strlen(a);
    reverse(a,a+len);
    cout<<a<<endl;
	}
   	return 0;
 }
