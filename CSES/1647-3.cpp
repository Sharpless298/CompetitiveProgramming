#include <bits/stdc++.h>
using namespace std;
 
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
 
	vector<vector<int>> data(32, vector<int>(n + 1));
	vector<int> mask(n + 1);
	auto f = [&](auto &&self, int level, int l, int r) -> void {
		if (r - l <= 1) {
			return;
		}
		
		int m = (l + r) / 2;
		data[level][m] = INT_MAX;
		for (int i = m - 1; i >= l; i--) {
			data[level][i] = min(data[level][i + 1], a[i]);
		}
		data[level][m] = a[m];
		for (int i = m + 1; i < r; i++) {
			data[level][i] = min(data[level][i - 1], a[i]);
		}
		for (int i = m; i < r; i++) {
			mask[i] ^= (1 << level);
		}
		self(self, level + 1, l, m);
		self(self, level + 1, m, r);
	};
 
	f(f, 0, 0, n);
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		if (l == r) {
			cout << a[l] << '\n';
		} else {
			int bits = __builtin_ctz(mask[l] ^ mask[r]);
			cout << min(data[bits][l], data[bits][r]) << '\n';
		}
	}
}
