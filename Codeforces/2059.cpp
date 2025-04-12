#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int &i : a)
		cin >> i;

	if (k == n) {
		for (int i = 1, j = 1; i < n; i += 2, j++) {
			if (a[i] != j) {
				cout << j << '\n';
				return;
			}
		}
		cout << k / 2 + 1 << '\n';
		return;
	}
	for (int i = 1; i < n - k + 2; i++) {
		if (a[i] != 1) {
			cout << 1 << '\n';
			return;
		}
	}
	cout << 2 << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--)
		solve();
}
