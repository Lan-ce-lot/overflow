/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 250;
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
struct node {
    string s_1, equal, s_2;
}N[maxn];
 
struct SET {
    set<char> S;
}SS[70];
set<char> amore[70][70];
 
inline bool check_low(char c) {
    return c >= 'a' && c <= 'z';
}
 
void solve()
{
    int n;
    n = read();
    for (int i = 0; i < n; i++) cin >> N[i].s_1 >> N[i].equal >> N[i].s_2;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            int l1 = N[i].s_1.size(), l2 = N[i].s_2.size();
            int tem_1 = N[i].s_1[0] - 'A', tem_2 = N[i].s_2[0] - 'A';
            if (l1 == 1 && l2 == 1) {
             
                if (check_low(N[i].s_2[0])) {
                    SS[tem_1].S.insert(N[i].s_2[0]);
                } else {
                    for (auto it : SS[tem_2].S) {
                        SS[tem_1].S.insert(it);
                    }
                }
            } else { // cap.low
                if (l1 == 3) {
                    int cap = N[i].s_1[0] - 'A', low = N[i].s_1[2] - 'a';
                    for (auto it_1 : SS[tem_1].S) {
                        for (auto it_2 : SS[tem_2].S) {
                            amore[it_1 - 'a'][low].insert(it_2);
                        }
                    }
                } else {
                    int cap = N[i].s_2[0] - 'A', low = N[i].s_2[2] - 'a';
                    for (auto it_1 : SS[tem_2].S) {
                        for (auto it_2 : amore[it_1 - 'a'][low]) {
                            SS[tem_1].S.insert(it_2);
                        }
                    }
                }
            }  
        }
 
    }
     
    for (int i = 0; i < 26; i++) {
        printf("%c: ", char(i + 'A'));
        for (auto it : SS[i].S) cout << it;
        puts("");
    }
}
 )
	{
	
)
    {
        	
int main()
{
 
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

