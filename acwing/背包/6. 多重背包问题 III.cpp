#include<iostream>
#include<cstring>
using namespace std;
#define debug(a) cout << "*" << a << "*" << endl
int a[100], b[100];
int main()
{
    for (int i = 0; i < 100; i++)
        b[i] = 10;
    memcpy(a, b, sizeof(b));

    for (int i = 0; i < 100; i++)
        cout << a[i] << endl;
    memset(a, 0, sizeof(a));
    for (int i = 0; i < 100; i++)
        cout << a[i] << endl;
    return 0;
}
