#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int MAXN = 2e5 + 5;
int m, p;
struct node{
	int l, r;
	int gcd, sum;
}tr[MAXN * 4];

void pushup(int p) {
	tr[p].sum = tr[p << 1].sum + 
}


int main() {
	int n = 0, last = 0, l, r, k;
	scanf("%d%d", &m, &p);
	build(1, 1, m);
	
	int x;
	char op[2];
	while (p--) {
		scanf("%s%d", op, &l, &r);
		if (*op == 'Q') {
			last = query(1, l, r);
			printf("%d\n", last);
		} else {
			scanf("%d", &k)
			modify(1, l, r, k);
//			n++;
		}
	}
	return 0;
}
