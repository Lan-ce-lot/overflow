#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

/* 求解 T 中  next1[]，注释参考 GetExtend() */
void GetNext(string & T, int & m, int  next1[])
{
    int a = 0, p = 0;
     next1[0] = m;

    for (int i = 1; i < m; i++)
    {
        if (i >= p || i +  next1[i - a] >= p)
        {
            if (i >= p)
                p = i;

            while (p < m && T[p] == T[p - i])
                p++;

             next1[i] = p - i;
            a = i;
        }
        else
             next1[i] =  next1[i - a];
    }
}

/* 求解 extend[] */
void GetExtend(string & S, int & n, string & T, int & m, int extend[], int  next1[])
{
    int a = 0, p = 0;
    GetNext(T, m,  next1);

    for (int i = 0; i < n; i++)
    {
        if (i >= p || i +  next1[i - a] >= p) // i >= p 的作用：举个典型例子，S 和 T 无一字符相同
        {
            if (i >= p)
                p = i;

            while (p < n && p - i < m && S[p] == T[p - i])
                p++;

            extend[i] = p - i;
            a = i;
        }
        else
            extend[i] =  next1[i - a];
    }
}
int  next1[1000001];
int extend[1000001];
int main()
{

    string S, T;
    int n, m;

    while (cin >> S >> T)
    {
        n = S.size();
        m = T.size();
        GetExtend(S, n, T, m, extend,  next1);

        // 打印  next1
//        cout << " next1:   ";
        for (int i = 0; i < m; i++)
            cout <<  next1[i] << " ";
        puts("");
        // 打印 extend
//        cout << "\ next1end: ";
        for (int i = 0; i < n; i++)
            cout << extend[i] << " ";
        puts("");
    }
    return 0;
}
