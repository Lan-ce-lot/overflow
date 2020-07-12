#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<assert.h>
using namespace std;
struct node {
string version;
vector<int>v;}
G[110];
bool cmp(const node &a, const node &b)
{ 
    for(int i = 0; ; i++)
	{ 
		if (i == (int)a.v.size()) 
		{  
			eturn 1;  
		}  
		if (i == (int)b.v.size()) 
		{  
			return 0; 
		}  
		if (a.v[i] < b.v[i])
		{  
		  	return 1;  
		} 
		if (a.v[i] > b.v[i]) 
		{	
			 return 0; 
		}  
	}
} 
	int main() 
	{  
	int n; 
	cin >> n;  
	for (int i = 0; i < n; i++) 
	{  
		string ss;  
		cin >> ss;  
		G[i].version = ss;  
		int cnt = 0;  
		for (int j = 0; j < ss.size(); j++) 
		{  
			if (ss[j] == '.') 
			{  
				G[i].v.push_back(cnt);  
				cnt = 0;  
			} 
			else 
			{  
				cnt = cnt * 10 + ss[j] - '0';  
			}  
		}  
			G[i].v.push_back(cnt);  
	}  
	sort(G, G + n, cmp); 
	for (int i =0; i < n; i++) 
	{  
		cout << G[i].version << endl; 
	}
	return 0; 
}
