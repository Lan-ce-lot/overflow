#include <iostream>
using namespace std;
const int N = 1e6;
int a, b, p, s, f[N], q[N], t, mp[N], mt, c, v[N], i, j;
int F(int x) {
	return f[x] = x != f[x] ? F(f[x]) : x;
}
int main() {
	cin >> a >> b >> p;
	for (i = 2; i <= b; i++) {
		if (!v[i]) q[t++] = i; 
		for (j = 0; q[j] <= b / i; j++) {
			v[q[j] * i] = 1;
			if (i % q[j] == 0) break;
		}
	}
	for (i = p; i <= b; i++)
		if (!v[i]) mp[mt++] = i;
	for (i = 1; i <= b; i++)
		f[i] = i;
	for (i = 0; i < mt; i++) {
		c = 0;
		while (c * mp[i] < a) c++;
		while ((c + 1) * mp[i] <= b)
			f[F(c * mp[i])] = F((c + 1) * mp[i]), c++;
	}
	for (i = a; i <= b; i++)
		s += (f[i] == i);
	cout << s << endl;
}
