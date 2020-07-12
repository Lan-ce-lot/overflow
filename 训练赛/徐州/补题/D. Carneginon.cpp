/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <vector>
#include <cstdio>
#include <bitset>
#include <string>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1e6 + 5;

int n, k, len1, len2;
int next1[maxn];
char s1[maxn];
char s2[maxn];
inline void get_next() //求出next数组
{
    //next数组是从 S[0到i-1]前子串 的前缀后缀最大值
    memset(next1, 0, sizeof(next1));
    int t1 = 0, t2;
    next1[0] = t2 = -1;
    while(t1 < len2)
        if(t2 == -1 || s2[t1] == s2[t2]) //类似于KMP的匹配
            next1[++t1] = ++t2;
        else
            t2 = next1[t2]; //失配
}

int KMP() //KMP
{
    int t1 = 0, t2 = 0; //从0位开始匹配
    while(t1 < len1) //临界值
    {
        if(t2 == -1 || s1[t1] == s2[t2]) //匹配成功，继续
            t1++, t2++;
        else
            t2 = next1[t2]; //失配
        if(t2 == len2)
        {
            t2 = next1[t2];
            return 1;
        }

//            printf("%d\n", t1 - len2 + 1), t2 = next1[t2]; //t2==lenn2时，匹配成功；t1-len2+1即为第一个字母的位置
    } //匹配成功后，t2置为next[t2]
    return 0;
}

int main()
{
//    ios::sync_with_stdio(false);
    scanf("%s", s1);
    len1 = strlen(s1);

    scanf("%d", &n);
    while (n--)
    {
        scanf(" %s", s2);
        len2 = strlen(s2);
        if (len1 == len2)
        {
            if (!strcmp(s1, s2))
            {
                puts("jntm!");
            }
            else
            {
                puts("friend!");
            }
        }
        else if (len1 < len2)
        {
            swap(len1, len2);
            char temp[maxn];
            strcpy(temp, s1);
            strcpy(s1, s2);
            strcpy(s2, temp);

            get_next();


            if (KMP())
            {
                puts("my teacher!");
            }
            else
            {
                puts("senior!");
            }
            strcpy(temp, s1);
            strcpy(s1, s2);
            strcpy(s2, temp);
        }
        else
        {
            get_next();
            if (KMP())
            {
                puts("my child!");
            }
            else
            {
                puts("oh, child!");
            }
        }

    }
    return 0;
}

