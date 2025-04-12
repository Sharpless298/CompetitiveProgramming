#include <algorithm>
#include <iostream>
using namespace std;

int ary[100005];

int lower_bound(int l, int r, int k) {
	while (l < r) {
		int m = (l + r) / 2;

		if (ary[m] < k)
			l = m + 1;
		else
			r = m;
	}

	return l;
}

int upper_bound(int l, int r, int k) {
	while (l < r) {
		int m = (l + r) / 2;

		if (ary[m] <= k)
			l = m + 1;
		else
			r = m;
	}

	return l;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q, a = 0x3f3f3f3f, b;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> ary[i];

	sort(ary, ary + n);

	cin >> q;
	while (q--) {
		if (a != 0x3f3f3f3f)
			cout << ' ';

		cin >> a >> b;
		cout << upper_bound(0, n, b) - lower_bound(0, n, a);
	}
}
