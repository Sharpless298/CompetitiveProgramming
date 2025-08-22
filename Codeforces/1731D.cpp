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
		vector<vector<int>> a(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}

		int left = 1, right = min(n, m) + 1;
		while (left < right) {
			int mid = (left + right) / 2;

			vector<vector<int>> b = a;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					b[i][j] = (b[i][j] >= mid);
				}
			}
			vector<vector<int>> pref(n + 1, vector<int>(m + 1));
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					pref[i + 1][j + 1] = pref[i][j + 1] + pref[i + 1][j] - pref[i][j] + b[i][j];
				}
			}

			bool f = false;
			for (int i = mid; i <= n; i++) {
				for (int j = mid; j <= m; j++) {
					if (pref[i][j] - pref[i][j - mid] - pref[i - mid][j] + pref[i - mid][j - mid] == mid * mid) {
						f = true;
					}
				}
			}

			if (f) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}

		cout << left - 1 << '\n';
	}
}
