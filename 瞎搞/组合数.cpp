#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
using namespace std;
const int M = 10007; 
const int MAXN = 1000; 
int C[MAXN+1][MAXN+1]; 
void Initial() 
{ 
    int i,j; 
    for(i=0; i<=MAXN; ++i) 
    { 
        C[0][i] = 0; 
        C[i][0] = 1; 
    } 
    for(i=1; i<=MAXN; ++i) 
    { 
        for(j=1; j<=MAXN; ++j) 
        C[i][j] = (C[i-1][j] + C[i-1][j-1]) % M; 
    } 
} 
int Combination(int n, int m) 
{ 
    return C[n][m]; 
} 
int main()
{
	int n, m;
	Initial();
	while (cin >> n >> m)
		cout <<Combination(n, m) << endl;
}
