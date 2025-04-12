#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 1e6 + 5;

int n, t;
int ary[MAXN];

int bsearch(int k) {
	int l = 0, r = n, m;

	while (l < r) {
		m = (l + r) / 2;
		if (ary[m] == k)
			return m;
		else if (ary[m] > k)
			r = m;
		else
			l = m + 1;
	}
	return l;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> ary[i];

	sort(ary, ary + n);

	cin >> t;

	for (int i = 0, x, k; i < t; i++) {
		cin >> x;

		k = bsearch(x);
		if (ary[k] == x)
			cout << x << '\n';
		else if (k == 0)
			cout << "no" << ' ' << ary[k] << '\n';
		else if (k == n)
			cout << ary[k - 1] << ' ' << "no" << '\n';
		else
			cout << ary[k - 1] << ' ' << ary[k] << '\n';
	}
}
