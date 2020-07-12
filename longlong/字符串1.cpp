#include<bits/stdc++.h> 

using namespace std;
const int INF=0x3f3f3f3f;

#define N 1000000
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))

string str;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		cin>>str;
		int cnt=0;
		for(int i=0;i<str.size();i++)
			str[i]>='0'&&str[i]<='9'?cnt++:i;
		cout<<cnt<<endl;
	} 
	return 0;
}
