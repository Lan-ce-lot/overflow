#include <bits/stdc++.h>
using namespace std;
string str;
int l, r;
int Manacher(string s)
{
    /*改造字符串*/
    string res="$#";
    for(int i=0;i<s.size();++i)
    {
        res+=s[i];
        res+="#";
    }

    /*数组*/
    vector<int> P(res.size(),0);
    int mi=0,right=0;   //mi为最大回文串对应的中心点，right为该回文串能达到的最右端的值
    int maxLen=0,maxPoint=0;    //maxLen为最大回文串的长度，maxPoint为记录中心点

    for(int i=1;i<res.size();++i)
    {
        P[i]=right>i ?min(P[2*mi-i],right-i):1;     //关键句，文中对这句以详细讲解

        while(res[i+P[i]]==res[i-P[i]])
            ++P[i];

        if(right<i+P[i])    //超过之前的最右端，则改变中心点和对应的最右端
        {
            right=i+P[i];
            mi=i;
        }

        if(maxLen<P[i])     //更新最大回文串的长度，并记下此时的点
        {
            maxLen=P[i];
            maxPoint=i;
        }
    }
    l = (maxPoint-maxLen) / 2, r = maxLen - 1;
    return s.substr((maxPoint-maxLen)/2,maxLen-1).size();
}

int main()
{
    cin >> str;
    int le = 0, ri = 0;
    int ans = Manacher(str),ans1 = 0;
    le = l, ri = r;
	if (le == 0)
	{
		if (ri + le >= str.size())
		{
			ans1 = 0;
		}
		else
		{
			ans1 = Manacher(str.substr(ri + le, str.size() - le - ri));
		}
		
	}
	else if (ri + le >= str.size())
	{
		ans1 = Manacher(str.substr(0, le - 1));
	}
	else
	{
		ans1 = max(Manacher(str.substr(ri + le, str.size() - le - ri)), Manacher(str.substr(0, le - 1)));
	}
	cout << ans + ans1;
    //cout << ans + max(Manacher(str.substr(0, le - 1)) , Manacher(str.substr(le + ri +1, str.size() - le - ri)))<< endl;
}
