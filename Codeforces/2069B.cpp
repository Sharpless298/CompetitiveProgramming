#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m));
		for (auto &i : a)
			for (auto &j : i)
				cin >> j, j--;

		int cnt = 0;
		vector<bool> f(n * m), two(n * m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!f[a[i][j]])
					f[a[i][j]] = true, cnt++;
				if (i + 1 < n && a[i][j] == a[i + 1][j] && !two[a[i][j]])
					two[a[i][j]] = true, cnt++;
				if (j + 1 < m && a[i][j] == a[i][j + 1] && !two[a[i][j]])
					two[a[i][j]] = true, cnt++;
			}
		}

		int ans = 0x3f3f3f3f;
		for (int i = 0; i < n * m; i++)
			ans = min(ans, cnt - two[i] - 1);
		cout << ans << '\n';
	}
}
