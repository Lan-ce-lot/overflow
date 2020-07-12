#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
string str[] = { "Danil", "Olya", "Slava", "Ann" , "Nikita" };
 
string S;
 
int main()
{
	cin >> S;
	int flag = 0;
	for (int i = 0; i < 5; i++) 
	{
		for (int j = 0; j < S.size(); j++) 
		{
			if (S.substr(j, str[i].size()) == str[i])
			{
				flag++;
			}
		}
	}
	if (flag == 1)
	{
		puts("Yes\n");
	}
	else
	{
		puts("No\n");
	}
	return 0;
}

