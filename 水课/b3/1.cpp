#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
#include<vector> 
using namespace std;
typedef long long ll;
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
int main()

{
	int a[15]={1,1,2};
	for(int i=3;i<=10;i++)
	{
		for(int j=1;j<i-1;j++)
		{
			a[i]+=a[j];
		}

		cout<<a[i]<<endl;
	}

	

//	system("pause");
	return 0;

}
