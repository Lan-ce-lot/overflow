#include <iostream>
int n, i;
void d(int u, int s) {
    if (u == n) {
        for (i = 0; i < n; i++) if(s >> i & 1) std::cout << i + 1 << ' ';
        puts("");
        return;
    }
    d(u + 1, s);
    d(u + 1, s | 1 << u);
}

int main() {
    std::cin >> n;
    d(0, 0);
}