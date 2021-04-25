/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000005;
class Heap{
	int heap[maxn], n;
	
	void up(int p) {
		while (p > 1) {
			if (heap[p] > heap[p / 2]) {
				swap(heap[p] > heap[p / 2]);
				p / 2;
			} else break;
		}
	}
	
	void Insert(int val) {
		heap[++n] = val;
		up(n);
	}
	int GetTop() {
		return heap[1];
	}
	
	void down(int p) {
		int s = p * 2;
		while (s <= n) {
			if ( s < n && heap[s] < heap[s + 1]) s++;
			if (heap[s] > heap[p]) {
				swap(heap[s], heap[p]);
				p = s, s = p * 2;
			} else break;
		}
	}
	
	void Extract() {
		heap[1] = heap[n--];
		down(1);
	}
	
	void Remove(int k) {
		heap[k] = heap[n--];
		up(k), down(k);
	}
	
	void Merge(int *h1, int *h2, int *res, int n) {
		for (int i = 1; i <= n; i++)
			ans[i] = h1[i];
		for (int i = 1; i <= n; i++) {
			ans[++n] = h2[i];
			up(n);
		}
	}
};



int main() {
	for (int i = 1; i <= n; i++) {
		cin >> a;
	}
}

