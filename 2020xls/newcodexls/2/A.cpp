#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
typedef long long ll;
using namespace std;
const int MAXN = 1e6 + 5;
int t, n, a[1005];


int main() {
	string str,str2;
	string ans;
	stringstream ss;
	cin >> str >> str2;
//	ss.str(str);
//¡¡¡¡ss>>x;
	int h = str[0] * 10 + str[1];
	int m = str[2] * 10 + str[3];
	int s = str[4] * 10 + str[5];
	int tem1 = h * 3600 + m * 60 + s;
	int h1 = str2[0] * 10 + str2[1];
	int m1 = str2[2] * 10 + str2[3];
	int s1 = str2[4] * 10 + str2[5];
    return 0;
}
