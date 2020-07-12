#include<bits/stdc++.h>
using namespace std;
struct node{
	string rnum;
	int snum,znum;
};
int main()
{
	int n,t;
	node a[1005];
	scanf("%d",&n);
	while(n--)
	{
		string str;
		int aa,bb;
		cin>>str;
		scanf("%d%d",&aa,&bb);
		a[aa].znum=bb;
		a[aa].rnum=str;
	 }
	scanf("%d",&t);
	while(t--)
	{
		int aa;
		scanf("%d",&aa);
		cout<<a[aa].rnum<<' '<<a[aa].znum<<endl;
	}
	return 0;
}
