#include<iostream>
using namespace std;
int lower_bound(int *a, int n, int value) //���ֲ��ҵ�һ�����ڻ����value���±�key
{
	int l = 0;
	int r = n - 1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (a[mid] < value)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return l;
}
int upper_bound(int *a, int n, int value) // ���ص�һ������value��key
{
	int l = 0;
	int r = n - 1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (a[mid] <= value)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return l;
}
//������С�� 
//		while(l<=r){//�����������Сֵ
//			int mid=(l+r)>>1;
//			if(a[mid]<w) r=mid-1;
//			else l=mid+1;
//		}

int main()
{
	int input[20] = {0, 2, 3, 4, 4, 5, 5, 7, 8, 9};
	int key1,key2;
	key1 = lower_bound(input, 10, 4);
	key2 = upper_bound(input, 10, 5);
	cout << key1 << "\t" << key2 << endl;
	return 0;
}
