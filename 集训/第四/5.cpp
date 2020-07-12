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
	string name,str[5] = { "Danil", "Olya", "Slava", "Ann" , "Nikita" };
	cin>>name;
	int flag = 0;
	for (int i = 0; i < 5; i++) 
	{
		for (int j = 0; j < name.size(); j++) 
		{
			if (name.substr(j, str[i].size()) == str[i])
				flag++;
		}
	}
	flag==1?printf("YES\n"):printf("NO\n");
	return 0;
}
