//方法1：
#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n;
string s, ss;
string S[110];
int main()
{
    //freopen("/Users/zhangkanqi/Desktop/11.txt","r",stdin);
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++)
    {
        getline(cin, s);
        if(s.find("ong,")!=string::npos && s.find("ong.")!=string::npos)
        {
            stringstream sin(s);
            int num = 0;
            while(sin >> ss)
                S[num++] = ss;
            ss.clear();
            // 0 1 2 3
            // a b c d  num=4
            for(int k = 0; k < num; k++)
            {
                if(k) printf(" ");
                if(k == num-3)
                {
                    printf("qiao ben zhong.\n");
                    break;
                }
                cout << S[k];
            }
        }
        else printf("Skipped\n");
    }
    return 0;
}
//方法2：
/*#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
    //freopen("/Users/zhangkanqi/Desktop/11.txt","r",stdin);
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++)
    {
        getline(cin, s);
        bool f1 = false, f2 = false;
        int cnt = 0;
        for(int k = 0; k < s.length(); k++)
        {
            if(s[k]==',' && s[k-1]=='g' && s[k-2]=='n' && s[k-3]=='o') f1= true;
            if(s[k]=='.' && s[k-1]=='g' && s[k-2]=='n' && s[k-3]=='o') f2= true;
            if(s[k] == ' ') cnt++;
        }
        //a b c d cnt=3, 第3-2个
        if(f1 && f2)
        {
            int num = 0;
            for(int k = 0; k < s.length(); k++)
            {
                if(s[k] == ' ') num++;
                if(num == cnt-2)
                {
                    printf(" qiao ben zhong.\n");
                    break;
                }
                printf("%c", s[k]);
            }
        }
        else printf("Skipped\n");
    }
    return 0;
}*/