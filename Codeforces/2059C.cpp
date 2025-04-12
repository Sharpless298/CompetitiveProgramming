#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> a(n, vector<int>(n));
		for (auto &i : a)
			for (auto &j : i)
				cin >> j;

		for (auto &i : a)
			reverse(i.begin(), i.end());
		sort(a.begin(), a.end());
		bool f = false;
		for (int i = n - 2; i >= 0; i--) {
			bool ok = true;
			for (int j = 0; j <= i; j++) {
				if (a[i - j][j] != 1) {
					ok = false;
					break;
				}
			}
			if (ok) {
				f = true;
				cout << i + 2 << '\n';
				break;
			}
		}
		if (!f)
			cout << 1 << '\n';
	}
}
