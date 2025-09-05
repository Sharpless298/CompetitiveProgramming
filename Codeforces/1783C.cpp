#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		vector<int> b = a;
		sort(b.begin(), b.end());
		int c = 0;
		for (int i = 0; i < n && b[i] <= m; i++) {
			m -= b[i];
			c++;
		}
		if (c != 0 && c != n && m + b[c - 1] >= a[c]) c++;
		cout << n + 1 - c << '\n';
	}
}
