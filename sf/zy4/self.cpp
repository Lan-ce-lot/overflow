#include <bits/stdc++.h>

using namespace std;
int a, b, c, d, br[3], A, B, C, D, Y1, Y2;
int main() {
    a = 1;
    cin >> b >> c >> d;
    b = -b, c = -c, d = -d;
    A = b - 3 * c;
    B = b * c - 9 * d;
    C = c * c - 3 * b * d;
    D = B * B - 4 * A * C;
    if (A == B && !A)
        br[0] = br[1] = br[2] = -c / b;
    else if (D > 0) {
        Y1 = (A * b + 3 * a * ((-B + pow(B * b - 4 * A * C, 0.5)))) / 2
        br[0] = ;
    }

    sort(br, br + 3);
    cout << br[0] << ' ' << br[1] << ' ' << br[2];
}