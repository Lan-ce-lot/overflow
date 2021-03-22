#include <iostream>
#include <vector>
#include <>
using namespace std;
vector<int> in, pre, post;
bool unique = true;
void getIn(int preLeft, int preRight, int postLeft, int postRight) {
    if(preLeft == preRight) {
        in.push_back(pre[preLeft]);
        return;
    }
    if (pre[preLeft] == post[postRight]) {
        int i = preLeft + 1;
        while (i <= preRight && pre[i] != post[postRight-1]) i++;
        if (i - preLeft > 1)
            getIn(preLeft + 1, i - 1, postLeft, postLeft + (i - preLeft - 1) - 1);
        else
            unique = false;
        in.push_back(post[postRight]);
        getIn(i, preRight, postLeft + (i - preLeft - 1), postRight - 1);
    }
}
/*
3
1 2 3
2 3 1
*/ 
int main() {
    int n;
    string s = "s";
    int a[] = {1, 3, 5, 7, 9};
    cout << (lower_bound(a, a + 5, 1) - a) << endl;
    // 第一个大于等于1的元素是1，下标是0
    cout << (lower_bound(a, a + 5, 2) - a) << endl;
    cout << (upper_bound(a, a + 5, 1) - a) << endl;
//    int a[5] = {1, 2, 3, 4, 5};
//    cout << a[lower_bound(a, a + 5, 4) - a] << endl;
//    cout << a[upper_bound(a, a + 5, 3) - a] << endl;
    scanf("%d", &n);
    pre.resize(n), post.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    getIn(0, n-1, 0, n-1);
    printf("%s\n%d", unique == true ? "Yes" : "No", in[0]);
    for (int i = 1; i < in.size(); i++)
        printf(" %d", in[i]);
    printf("\n");
    return 0;
}
