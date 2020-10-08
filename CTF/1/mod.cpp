#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
using namespace std;
typedef long long ll;
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
char flag[100], road[100], step[100]; 
int main(int argc, const char **argv, const char **envp)
{
  int v3; // eax
  int v5; // [esp+14h] [ebp-4Ch]
  int v6; // [esp+3Ch] [ebp-24h]
  int v7; // [esp+40h] [ebp-20h]
  int v8; // [esp+44h] [ebp-1Ch]
  int v9; // [esp+48h] [ebp-18h]
  int v10; // [esp+4Ch] [ebp-14h]
  size_t v11; // [esp+50h] [ebp-10h]
  int v12; // [esp+54h] [ebp-Ch]
  int i; // [esp+58h] [ebp-8h]
  int v14; // [esp+5Ch] [ebp-4h]

  puts("There is a long way to defeat it.");
  scanf("%s", flag);
  v12 = strlen(flag);
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v14 = 0;
  v11 = 0;
//  cout << *(&v6 + 4) << endl;
//  debug(*(&v6 + 4));
  for ( i = 0; i < v12; ++i )
  {
    if ( flag[i] == 45 )// -
    {
      v3 = v14++;
      *(&v6 + v3) = i;
    }
    if ( !v14 ) //0
    {
      *(&v5 + i) = flag[i] - 48; // '0'
      if ( *(&v5 + i) > 9 || *(&v5 + i) < 0 )
        return 0;
    }
  }
    if ( v14 != 4 )
    return 0;
  cout <<v3 << ' ' <<  v6<< ' ' << v7<< ' '<<v8<< ' ' <<v9<< ' ' <<v10<< ' ' <<v14<< ' ' <<v11<< ' ' << endl;
  for ( i = 1; i <= v14; ++i )
  {
    v11 = *(&v6 + i) - *(&v6 + i - 1) - 1;
    if ( step[i] != v11 )
      return 0;
    strncpy(&road[200 * i], &flag[*(&v6 + i - 1) + 1], v11);
  }
}
