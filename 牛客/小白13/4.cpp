#include <iostream>
#include<cstdio>
#include<map>
using namespace std;
map<int, int>Map;//ӳ�� ��map��  keyֵ ��ʾ a������ ���ڵ�ĳ���� value ��ʾ�������ڵĸ���
int a[111111];//������
int main()
{
        Map.clear();
        long i, n, q,ans=0,sum=0;
        int flag=0;
		cin>>n;
        for(i = 1;i <= n;i++)
        {
            int num;
            scanf("%d", &num);
            a[i] = num;
            Map[num]++;  
        }
        map<int ,int>::iterator it=Map.begin();
        for(it=Map.begin();it!=Map.end();it++)
        {
        	if(it->second>1)
        	{
        		flag=1;
        		break;
			}	
		}
		if(flag)
		{
			for(it=Map.begin();it!=Map.end();it++)
			{
				sum|=(it->first);
			}
			cout<<sum<<endl;
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				sum=0;int j=0;
				for(it=Map.begin();it!=Map.end();it++,j++)
			{
				i!=j?sum|=(it->first):i;
				ans=max(sum,ans);
			}
			}
			cout<<ans<<endl;
		}	
    return 0;
}
