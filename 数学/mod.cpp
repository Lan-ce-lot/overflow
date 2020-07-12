#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int gcd(int a,int b)
{
	return b == 0?a:gcd(b,a%b); 
}
int a[100];
int b=__gcd(1,2); //gcd

int len=10;


int main()
{
	sort(a,a+len,greater<int>());//从大到小排序 
//	system("pause");
	return 0;
}
