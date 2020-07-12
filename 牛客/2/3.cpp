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
int main()
{
	string s,t;int con=0;
	cin>>s;int ls=s.size(),lt=t.size();
	if(s=t)
	{
		puts("YES");return 0;
	}
	if(abs(ls-lt)>2)
	{
		puts("NO");return 0;
	}
	for(int i=0,z=0;i<ls&&z<lt;i++)
	{
		s.substr(0,i)==t.substr(z,z+i)?i:con++,z++;
		
	}
	puts("YES");
	return 0;
}
