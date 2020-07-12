#include<bits/stdc++.h>
using namespace std;
double f[202];
int main(){
    int T;
    scanf("%d",&T);
    for (int CS = 1; CS <= T; CS++) {
        int p;
        scanf("%d", &p);
        for (int i = 200; i <= 204; i++)
            f[i] = 100.0 / p;
        double pp = p / 100.0;
        for (int i = 199; i >= 4; i--) {
            f[i] = (1-pp)*f[i+3] + pp * (1-i/200.0)*f[i+4] + 1;
        }
        printf("Case %d: %.10lf\n", CS, f[4]);
    }
}
