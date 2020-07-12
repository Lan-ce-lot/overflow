//#include<bits/stdc++.h>
//using namespace std;
//
//stack<int> st;
//int f(int n)
//{
//    return (n == 0 || n == 1) ? 1 : n * f(n - 1);
//}
//
//int f1(int n)
//{
//    if (n != 0 && n != 1)
//    {
//        st.push(n);
//
//    }
//}
//
//int main()
//{
//    int i;
//    cin >> i;
//    cout << f(i) << endl;
//    return 0;
//}
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<stack>
using namespace std;
stack<int> st;
int f1(int n)
{
    int sum = 1;
    while (n)//µÝ¹é
        st.push(n--);

    while (!st.empty())//»ØËÝ
        sum *= st.top(), st.pop();

    return sum;

}

int f(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * f(n - 1);
}

//int f(int n)
//{
//    return (n == 0 || n == 1) ? 1 : n * f(n - 1);
//}

int main()
{
    int m;
    cin >> m;
    cout << f1(m) << endl;
}
