#include <bits/stdc++.h>

using namespace std;

void maxmin(int A[], int &e_max, int &e_min, int low, int high) {
    int mid, x1, y1, x2, y2;
    if (high - low <= 1) {
        if (A[high] > A[low]) {
            e_max = A[high];
            e_min = A[low];
        } else {
            e_max = A[low];
            e_min = A[high];
        }
    } else {
        mid = (low + high) / 2;
        maxmin(A, x1, y1, low, mid);
        maxmin(A, x2, y2, mid + 1, high);
        e_max = max(x1, x2);
        e_min = min(y1, y2);
    }
}
int A[]{8, 3, 6, 2, 1, 9, 4, 5, 7};
int main() {
    int e_max, e_min;
    int l = 0, r = 8;
    maxmin(A, e_max, e_min, l, r);
    cout << e_min << ' ' << e_max << endl;
    return 0;
}
