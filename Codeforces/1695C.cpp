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

		vector<vector<bitset<2001>>> dp(n, vector<bitset<2001>>(m));
		dp[0][0][1000 + a[0][0]] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i - 1 >= 0) {
					if (a[i][j] == 1) {
						dp[i][j] |= (dp[i - 1][j] << 1);
					} else {
						dp[i][j] |= (dp[i - 1][j] >> 1);
					}
				}
				if (j - 1 >= 0) {
					if (a[i][j] == 1) {
						dp[i][j] |= (dp[i][j - 1] << 1);
					} else {
						dp[i][j] |= (dp[i][j - 1] >> 1);
					}
				}
			}
		}

		cout << (dp[n - 1][m - 1][1000] ? "YES\n" : "NO\n");
	}
}
