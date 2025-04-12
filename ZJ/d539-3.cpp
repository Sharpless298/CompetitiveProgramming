#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int k;
vector<int> a, block;

int query(int l, int r) {
	int res = 0;
	for (int i = l; i < r; i++) {
		if (i / k != l / k)
			break;
		res = max(res, a[i]);
	}
	for (int i = r - 1; i >= l; i--) {
		if (i / k != (r - 1) / k)
			break;
		res = max(res, a[i]);
	}
	for (int i = l / k + 1; i < (r - 1) / k; i++)
		res = max(res, block[i]);

	return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	k = (int)sqrt(n);

	block.resize(n / k + 1);
	for (int i = 0; i < n; i++)
		block[i / k] = max(block[i / k], a[i]);

	int m;
	cin >> m;
	while (m--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		if (l > r)
			swap(l, r);

		cout << query(l, r + 1) << '\n';
	}
}
