#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
#define MAXN 5001
typedef long long ll;
int dp[5001][5001][14];
//int dp1[5001][5001][14];
int a[5001][5001];
int n,m, k;

// O(n*m*log(m))

void st(){
    for(int i=1;i<=n;i++)
    for(int k=0;(1<<k)<=m;k++){
    for(int j=1;j+(1<<k)-1<=m;j++){
        if(k==0){
            dp[i][j][k]=a[i][j];
        }
        else {
            dp[i][j][k]=max(dp[i][j][k-1],dp[i][j+(1<<(k-1))][k-1]);
//            dp1[i][j][k]=min(dp1[i][j][k-1],dp1[i][j+(1<<(k-1))][k-1]);
        }
    }
    }
}



int rmq2dmax(int x,int y,int x1,int y1){
    int k=log2(y1-y+1);
    int mm=max(dp[x][y][k],dp[x][y1-(1<<k)+1][k]);
    for(int i=x+1;i<=x1;i++)
        mm=max(mm,max(dp[i][y][k],dp[i][y1-(1<<k)+1][k]));
    return mm;
}
/*
200 400 2
1605820963
*/
//int rmq2dmin(int x,int y,int x1,int y1){
//    int k=log2(y1-y+1);
//    int mm=min(dp1[x][y][k],dp1[x][y1-(1<<k)+1][k]);
//    for(int i=x+1;i<=x1;i++)
//        mm=min(mm,min(dp1[i][y][k],dp1[i][y1-(1<<k)+1][k]));
//    return mm;
//}
 
int main () {
    ll ans = 0;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		if (a[i][j] == 0) {
    			for (int k = 1; k * i <= n && k * j <= m; k++) {
    				a[i * k][j * k] = i * j * k;
				}
			}
		}
	}
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            a[i][j] = lcm(i, j);
//        }
//    }
    st();
//  for (int i = 1; i <= n; i++) {
//      for (int j = 1; j <= m; j++) {
//          printf("%5d", a[i][j]);
//      }
//      puts("");
//  }
    for (int i = 1; i <= n - k + 1; i++) {
        for (int j = 1; j <= m - k + 1; j++) {
            ans += rmq2dmax(i, j, i + k - 1, j + k - 1);
//          cout << rmq2dmax(i, j, i + k - 1, j + k - 1) << endl;
        }
    }
    cout << ans << endl;
}
