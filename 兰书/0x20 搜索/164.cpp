#include <algorithm>
#include <bitset>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 3e4 + 10;

int n, m;
int h[N], e[N], ne[N], idx;
int d[N], seq[N];  //��ȣ� ��������

bitset<N> f[N];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

// ֻ�������޻�ͼ�� ��������������
// ��������
void topsort() {
    queue<int> q;

    // �Ȱ��������Ϊ 0 �ĵ������У�����ͼ��
    for (int i = 1; i <= n; i++) {
        if (!d[i]) {
            q.push(i);
        }
    }
    // k��ʾ��ǰ����������Ԫ�صĸ���
    int k = 0;
    while (q.size()) {
        int t = q.front();
        q.pop();
        seq[k++] = t;  //����ͷԪ�ؼ�����������
        //����ǰ����Ե��ĵ�����--��ɾȥx����������ıߣ�
        for (int i = h[t]; ~i; i = ne[i]) {  // ������������е��ڱ�
            int j = e[i];  // e[i] ��ʾ �ڱ�����Ӧ���յ�
            if (--d[j] ==
                0) {  //���j���������Ϊ0�ˣ������ǾͿ��Լӵ�������ȥ
                q.push(j);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;  //��һ�� a ָ�� b�ıߣ� ���b�����+1
    }

    topsort();

    // �Ӻ���ǰ����
    // bitset<N> s;
    // s[k] ��ʾ ��kλ�� �ȿ���ȡֵ�� Ҳ���Ը�ֵ
    for (int i = n - 1; i >= 0; i--) {
        int j = seq[i];
        f[j][j] = 1;  // j�������Ե����Լ�   f[j][j] =��ʾ�� j�����ĵ㣬
                      // �ܹ����ĵ㣨1��ʾ���Ե��� 0��ʾ���ܵ�����j���Ե��Լ���
                      // ���f[j][j]=1
        for (int k = h[j]; ~k; k = ne[k]) {  //�����ܵ�����ĵ�
            f[j] |= f[e[k]];  // j�������Ե���ĵ������= {j} U {y1} U {y2}
                              // ... {yn}
        }
    }
    for (int i = 1; i <= n; i++) {
        // f[i].count() ����f[i] �� 1�ĸ���
        cout << f[i].count() << endl;
    }
    return 0;
}
