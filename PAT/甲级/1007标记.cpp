#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, a[10005];
int dp[10005];
int main() {
	while (cin >> n) {
		int flag = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] >= 0) flag = 1;
		}
		int s_ind = 0, e_ind = n - 1, MAX = -1, temp = 0, temp_ind = 0;
		for (int i = 0; i < n; i++) {
			temp += a[i];
			if (temp < 0) {
				temp = 0;
				temp_ind = i + 1;
			} else if (temp > MAX){
				MAX = temp;
				s_ind = temp_ind;
				e_ind = i;
			}
		}
		if (!flag) {
			cout << 0 << ' ' << a[0] << ' ' << a[n -1 ] << endl;
			continue;
		}
		if (MAX < 0) MAX = 0;
		cout << MAX << ' ' << a[s_ind] << ' ' << a[e_ind] << endl;
	}
}

//#include <iostream>
//#include <vector>
//using namespace std;
//int main() {
//    int n;
//    scanf("%d", &n);
//    vector<int> v(n);
//    int leftindex = 0, rightindex = n - 1, sum = -1, temp = 0, tempindex = 0;
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &v[i]);
//        temp = temp + v[i];
//        if (temp < 0) {
//            temp = 0;
//            tempindex = i + 1;
//        } else if (temp > sum) {
//            sum = temp;
//            leftindex = tempindex;
//            rightindex = i;
//        }
//    }
//    if (sum < 0) sum = 0;
//    printf("%d %d %d", sum, v[leftindex], v[rightindex]);
//    return 0;
//}
