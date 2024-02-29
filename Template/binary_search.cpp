#include <iostream>
using namespace std;

int ary[10] = {0, 1, 3, 5, 5, 5, 6, 7, 9 , 12};

bool binary_search(int l, int r, int k) {
	int m;
	
	while(l < r) {
		m = (l+r)/2;
		if(ary[m] == k)
			return true;
		else if(ary[m] < k) 
			l = m+1;
		else
			r = m;
	}

	return false;
}

int lower_bound(int l, int r, int k) {
	int m;
	
	while(l < r) {
		m = (l+r)/2;
		if(ary[m] < k)
			l = m+1;
		else
			r = m;
	}

	return l;
}

int upper_bound(int l, int r, int k) {
	int m;

	while(l < r) {
		m = (l+r)/2;
		if(ary[m] <= k)
			l = m+1;
		else
			r =m;
	}

	return l;
}

signed main() {

	int k;

	for(int i=0; i<10; i++)
		cout << ary[i] << ' ';
	cout << '\n';

	while(cin >> k) {
		cout << "binary_search: " << binary_search(0, 10, k) << '\n';
		cout << "lower_bound: " << lower_bound(0, 10, k) << '\n';
		cout << "upper_bound: " << upper_bound(0, 10, k) << '\n';
	}
}
