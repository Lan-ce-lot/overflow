#include <bits/stdc++.h>

using namespace std;
int n, m;
const int maxn = 1e5 + 5;
int h[maxn], a[maxn], r = 0;
map<int, int> MM;
void up(int x, int p) {
    while (p > 1) {
        if (h[p] < h[p / 2]) {
			MM[h[p / 2]] = p,
			MM[h[p]] = p / 2;
            swap(h[p], h[p / 2]);
            p >>= 1;
        } else break;
    }
}

void insert(int x) {
    h[++r] = x, MM[x] = r;
    up(x, r);
}

string s[105];
vector<string> M[105];
/*
24 is the root
26 and 23 are siblings
46 is the parent of 23
23 is a child of 10

*/
void get(string s, int k) {
    s += ' ';
    int res = 0;
    for (int i = 0, j = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
//        	cout << s.substr(j, i - j + 1) << endl;
            M[k].push_back(s.substr(j, i - j));
            j = i + 1;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i], insert(a[i]);
	
    getchar();
    for (int i = 1; i <= m; i++) {
        getline(cin, s[i]);
        get(s[i], i);
    }
    for (int i = 1; i <= m; i++) {
    	int a, b;
    	if (M[i].size() == 4) {
    		a = stoi(M[i][0]);
    		if (h[1] == a) {
    			puts("T");
			} else {
				puts("F");
			}
		} else if (M[i].size() == 5) {
			a = stoi(M[i][0]);
			b = stoi(M[i][2]);
			if (MM[a] / 2 == MM[b] / 2) {
				puts("T");
			} else {
				puts("F");
			}
		} else if (M[i].size() == 6) {
			a = stoi(M[i][0]);
			b = stoi(M[i][5]);
			if (M[i][2] == "the") {
				if (MM[a]  == MM[b] / 2) {
					puts("T");
				} else {
					puts("F");
				}
			} else {
//				cout << MM[a] / 2 << ' ' << MM[b] << endl;
				if (MM[a] / 2 == MM[b]) {
					puts("T");
				} else {
					puts("F");
				}
			}
		}
    }
    return 0;
}
