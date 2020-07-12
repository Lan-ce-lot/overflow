#include <iostream>
#include<cstdio>
#include<map>
using namespace std;
map<int, int>Map;//映射 该map的  key值 表示 a数组中 存在的某个数 value 表示该数存在的个数
int a[111111];//该数组
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
