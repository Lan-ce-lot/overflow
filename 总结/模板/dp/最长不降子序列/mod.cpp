#include <cstdio>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;
int mupper_bound(int *a, int *b, int x)
{
    int l = 0, r = (b - a) - 1;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if (x >= *(a + mid))
            l = mid + 1;
        else
            r = mid -1;
    }
    return l;
}
int main()
{
    int a[7] = {1, 0, 2, 3, 4, 4, 5};
    cout << mupper_bound(a, a + 7, 2) << endl;

    return 0;
}
