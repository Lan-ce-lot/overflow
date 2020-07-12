///*************************************************************************
// > FileName:
// > Author:      Lance
// > Mail:        lancelot_hcs@qq.com
// > Date:        9102.1.8
// > Description:
// ************************************************************************/
////#include <bits/stdc++.h>
////#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
//#include <algorithm>
//#include <iostream>
//#include <cstdlib>
//#include <cstring>
//#include <sstream>
//#include <vector>
//#include <cstdio>
//#include <bitset>
//#include <string>
//#include <cmath>
//#include <deque>
//#include <queue>
//#include <stack>
//#include <map>
//#include <set>
//using namespace std;
//typedef long long ll;
//typedef pair<int, int> PII;
//const double pi = acos(-1.0);
//const double eps = 1e-6;
//const int mod = 1e9 + 7;
//#define debug(a) cout << "*" << a << "*" << endl
//const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
//const int maxn = 1000005;
////sacnf("%lf") printf("%f")
//ll read()
//{
//    ll x = 0,f = 1;
//    char ch = getchar();
//    while (ch < '0' || ch > '9')
//	{
//		if (ch == '-')
//		f = -1;
//		ch = getchar();
//	}
//    while (ch >= '0' && ch <= '9')
//	{
//		x = x * 10 + ch - '0';
//		ch = getchar();
//	}
//    return x * f;
//}
//int t, n;
//
//void solve()
//{
//    t = read();
//    int con = 0;
//    while (t--)
//    {
//        con++;
//        double x, y;
//        cin >> x >> y;
//        double tem = pi / 2.0 * (x * x + y * y);
//        cout<< "Property " << con <<": This property will begin eroding in year "<<(int)(tem / 50.0 + 1)<<"."<<endl;
//    }
//    puts("END OF OUTPUT.");
//}
//
//int main()
//{
//
////    freopen("F:/Overflow/in.txt","r",stdin);
////    ios::sync_with_stdio(false);
//    solve();
//    return 0;
//}
#include<iostream>
#include<cmath>
using namespace std;

int main(void)
{
    int cases;
    cin>>cases;
    for(int c=1;c<=cases;c++)
    {
        char left[3][6],right[3][6],status[3][6];

        int time['L'+1]={0};  //标记各个字母被怀疑的次数
        bool zero['L'+1]={false};  //标记绝对为真币的字母（令天枰平衡的所有字母）

        for(int k=0;k<3;k++)
            cin>>left[k]>>right[k]>>status[k];

        for(int i=0;i<3;i++)
        {
            switch(status[i][0])  //检查天枰状态
            {
                case 'u':     //up，天枰左重右轻
                    {
                        for(int j=0;left[i][j];j++)
                        {
                            time[ left[i][j] ]++;  //左重
                            time[ right[i][j] ]--;  //右轻
                        }
                        break;
                    }
                case 'd':     //down，天枰左轻右重
                    {
                        for(int j=0;left[i][j];j++)
                        {
                            time[ left[i][j] ]--;  //左轻
                            time[ right[i][j] ]++;  //右重
                        }
                        break;
                    }
                case 'e':     //down，天枰平衡
                    {
                        for(int j=0;left[i][j];j++)
                        {
                            zero[ left[i][j] ]=true;   //绝对真币
                            zero[ right[i][j] ]=true;   //绝对真币
                        }
                        break;
                    }
            }
        }

        int max=-1;  //查找被怀疑程度最高的硬币（假币）
        char alpha;
        for(int j='A';j<='L';j++)
        {
            if(zero[j])  //绝对真币
                continue;

            if(max<=abs(time[j]))
            {
                max=abs(time[j]);
                alpha=j;
            }
        }

        cout<<alpha<<" is the counterfeit coin and it is ";
        if(time[alpha]>0)
            cout<<"heavy."<<endl;
        else
            cout<<"light."<<endl;
    }
    return 0;
}
