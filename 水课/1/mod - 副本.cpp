#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
using namespace std;
typedef long long ll;
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
string a,b;
int main()
{
	int c=0;
	getline(cin,a);
	getline(cin,b);
	for(int i=0;i<=a.size()-b.size();i++)
	{
		if(a.substr(i,b.size())==b)
			c++;
	}
	cout<<c;
	return 0;

}
