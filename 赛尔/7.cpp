#include<bits/stdc++.h> 

using namespace std;
struct st{
	int H;
	string sex,name;
};
string N="boy",Nu="girl";
bool cmp(st a,st b)
{
	if(a.H==b.H)
		return a.name<b.name;
	return a.H<b.H;
}
int main()

{
	int n,r,l,ri;
	scanf("%d%d",&n,&r);
	st s1[n];
	for(int i=0;i<n;i++)
	{
		cin>>s1[i].name>>s1[i].sex>>s1[i].H;
		if(s1[i].sex=="boy")
		l++;
		else
		ri++;
	}
	st G[ri],B[l];
	for(int i=0,z=0,y=0;i<n;i++)
	{
		
		if(s1[i].sex=="boy")
		{
			B[z].name=s1[i].name;
			B[z++].H=s1[i].H;
		}
		else
		{
			G[y].name=s1[i].name;
			G[y++].H=s1[i].H;
		}
	}
	sort(G,G+ri,cmp);
	sort(B,B+l,cmp);
	int idex=0;

	for(int i=0,i1=0;idex<n;)
	{
		for(int j=0;j<r;j++,idex++)
		{
			if(j&1)
			{
				if(i<=l)
				j==r-1?cout<<B[i++].name<<endl:cout<<B[i++].name<<' ';
			}
			else
			{
				if(i1<=ri-1)
				j==r-1?cout<<G[i1++].name<<endl:cout<<G[i1++].name<<' ';
			}
			
			
		}
	}
	return 0;

}
