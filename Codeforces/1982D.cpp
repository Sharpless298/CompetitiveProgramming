#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>> a(n, vector<int>(m));
		for (auto &i : a)
			for (auto &j : i)
				cin >> j;

		long long D = 0;
		vector<vector<int>> b(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char c;
				cin >> c;
				b[i][j] = (c == '0' ? 1 : -1);
				if (b[i][j] == 1)
					D += a[i][j];
				else
					D -= a[i][j];
			}
		}

		vector<vector<int>> pref(n + 1, vector<int>(m + 1));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				pref[i + 1][j + 1] = pref[i][j + 1] + pref[i + 1][j] + b[i][j] - pref[i][j];

		long long g = 0;
		for (int i = k; i <= n; i++)
			for (int j = k; j <= m; j++)
				g = __gcd(g, 1LL * pref[i][j] - pref[i][j - k] - pref[i - k][j] + pref[i - k][j - k]);

		if ((g == 0 && D == 0) || (g != 0 && D % g == 0))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
