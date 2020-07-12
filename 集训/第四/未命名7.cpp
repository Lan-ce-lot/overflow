#include<iostream>
using namespace std;
int main()
{
int a[6];
int sum = 0;
for (int i = 0; i < 6; i++)
{
cin >> a[i];
sum += a[i];
}
if (sum % 2 != 0)
{
cout << "NO" << endl;
return 0;
}
int flag = 0;
for (int i = 0; i < 4; ++i)
{
for (int j = i + 1; j < 5; ++j)
{
for (int k = j + 1; k < 6; ++k)
{
if ((a[i] + a[j] + a[k]) == (sum / 2))
{
flag = 1;
break;
}
}
}
}
if (flag)
cout << "YES" << endl;
else
cout << "NO" << endl;
return 0;
}
