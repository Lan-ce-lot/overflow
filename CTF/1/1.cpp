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
char flag; 
char start;

bool __cdecl check_flag(int a1, int a2, char *a3)
{
  bool result; // eax
  signed int v4; // [esp+10h] [ebp-18h]
  int v5; // [esp+14h] [ebp-14h]
  int v6; // [esp+18h] [ebp-10h]
  int i; // [esp+1Ch] [ebp-Ch]

  v4 = strlen(a3);
  v6 = start[2 * a2];
  v5 = dword_403444[2 * a2];
  for ( i = 0; ; ++i )
  {
    result = i;
    if ( i >= v4 )
      break;
    switch ( a3[i] )
    {
      case 119:// w
        --v6;
        break;
      case 115:// s
        ++v6;
        break;
      case 97://a
        --v5;
        break;
      case 100://d
        ++v5;
        break;
      default:
        return 1;
    }
    if ( v5 < 0 || v5 > 19 || v6 < 0 || v6 > 10 )
      return 1;
    if ( v4 - 1 == i )
      return *(_BYTE *)(a1 + 20 * v6 + v5) != 100;
    if ( *(_BYTE *)(a1 + 20 * v6 + v5) != 46 )
      return 1;
  }
  return result;
}


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
  for ( i = 0; i < v12; ++i )
  {
    if ( flag[i] == 45 )// -
    {
      v3 = v14++;
      *(&v6 + v3) = i;
    }
    if ( !v14 )
    {
      *(&v5 + i) = flag[i] - 48;
      if ( *(&v5 + i) > 9 || *(&v5 + i) < 0 )
        return 0;
    }
  }
  if ( v14 != 4 )
    return 0;
  v10 = v12;
  for ( i = 1; i <= v14; ++i )
  {
    v11 = *(&v6 + i) - *(&v6 + i - 1) - 1;
    if ( step[i] != v11 )
      return 0;
    strncpy(&road[200 * i], &flag[*(&v6 + i - 1) + 1], v11);
  }
  for ( i = 0; i <= 3; ++i )
  {
    if ( check_flag((int)&global_map + 200 * *(&v5 + i), *(&v5 + i), &road[200 * (i + 1)]) )
    {
      puts("How about try again?");
      return 0;
    }
    if ( i == 3 )
      printf("Great! We will defeat it!!! your flag is flag{%s}", flag);
  }
  return 0;
}
