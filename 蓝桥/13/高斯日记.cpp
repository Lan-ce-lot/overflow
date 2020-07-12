#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

bool test(int y)
{
	return (y % 4 == 0&& y % 100 != 0 || y % 400 == 0);
}

int main()
{
	//1777
	//4
	//30
	int n;//8113
	cin >> n;
	int y = 1777;
	int m = 4;
	int d = 30;
	d--;
	int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	for (int i = 1; i <= n; i++, d++)
	{
		
		if (d > month[m])
		{
			d = 1;
			m++;
		}
		if (m > 12)
		{
			m = 1;
			y++;
			if (test(y))
			{	
				month[2] = 29;
			}
			else
			{
				month[2] = 28;
			}
		}
	}
	cout << y << ' ' << m << ' ' << d << endl;
 } 
 //1801 9 18
