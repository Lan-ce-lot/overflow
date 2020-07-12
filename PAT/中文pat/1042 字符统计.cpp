#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	int ans[200];
	memset(ans,0,sizeof(ans));
	getline(cin,str);
	int length=str.size();
	for(int i=0;i<length;i++)
	{
		if(str[i]>='a'&&str[i]<='z'||(str[i]>='A'&&str[i]<='Z'))
		{
			int b=0;
			if(str[i]>='A'&&str[i]<='Z')
			{
				str[i]+=32;				
			}

			b=str[i];
			
			ans[b]++;
		}
//		char(b[0])
	}
	printf("%c %d\n",char(max_element(ans,ans+200)-ans),*max_element(ans,ans+200));
	return 0;
}
