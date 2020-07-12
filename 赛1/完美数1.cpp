#include<bits/stdc++.h> 

using namespace std;
int bbj[8]={6,28,496,8128,130816,2096128,33550336};
int main()

{
	int a,b;int z=0;
	scanf("%d%d",&a,&b);
	for(int i=0;i<8;i++)
	{
		
		if(a<=bbj[i]&&b>=bbj[i])
	{
		z==0?printf("%d",bbj[i]):printf(" %d",bbj[i]);
		z++;
	}
	}
	if(z==0)
	puts("None");
	


	return 0;

}
