#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e3 +5;
unsigned seed =
    std::chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 mt(seed);
//����

int n, a[MAX_N];

void solve() {
    int ans = 0;  //��

    //��i<j<k���������ӾͲ��ᱻ�ظ�ѡ����

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int len = a[i] + a[j] + a[k];  //�ܳ�

                int ma = max(a[i], max(a[j], a[k]));  //����ӵĳ���

                int rest = len - ma;  //�����������ӵĳ���֮��

                if (ma < rest) {
                    //������������Σ�������Ը��´������

                    ans = max(ans, len);
                }
            }
        }
    }

    //���

    // printf("%d ", ans);
}

int main() {
    n = 0;
    while (n < 2e3) {
        n+=50;

        for (int i = 0; i < n; i++) {
            a[i] = 100 + mt() % 100;
            // scanf("%d", &a[i]);
        }
        clock_t start = clock(), end;
        solve();
        end = clock();
        // �������ʱ��
        cout << "n"
             << " = " << n << "  " << int(end - start) * 1000 / CLOCKS_PER_SEC
             << "ms" << endl;

    }
}
