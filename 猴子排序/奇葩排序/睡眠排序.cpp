/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
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
#include<chrono>
#include<iostream>
#include<thread>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1000005;
//sacnf("%lf") printf("%f")
ll read()
{
    ll x = 0,f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
	{
		if (ch == '-')
		f = -1;
		ch = getchar();
	}
    while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
    return x * f;
}
int t, n;


void SleepSort(const int i, const int offset)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(i + offset));
	std::cout << i << " ";
}

int S_Sort()
{
	std::cout << "Sorted array is:\n";
	std::vector<std::thread> threads;
	std::vector<int> num;
	int x;
	while (std::cin >> x )
		num.push_back(x);
	//for (int i = 0; i < num.size(); ++i)
	//	threads.push_back(std::thread(SleepSort, num[i]));

	//添加负值排序
	std::vector<int> data;
	data.reserve(num.size() - 1);
	for (int i = 0; i < num.size(); ++i)
		data.push_back(num[i]);
	const int minElem = std::abs(*std::min_element(data.begin(), data.end()));  //min_element寻找范围 [first, last) 中的最小元素。
	for (int i = 0; i < num.size(); ++i)
		threads.push_back(std::thread(SleepSort, num[i], minElem));

	for (auto& thread : threads)
		thread.join();

	return 0;
}


void solve()
{
    S_Sort();
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

