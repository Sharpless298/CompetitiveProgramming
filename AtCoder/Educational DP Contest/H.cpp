#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w;
	cin >> h >> w;
	vector<string> a(h);
	for (int i = 0; i < h; i++) {
		cin >> a[i];
	}

	vector<vector<int>> dp(h, vector<int>(w));
	dp[0][0] = 1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] != '#') {
				if (j - 1 >= 0) {
					dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
				}
				if (i - 1 >= 0) {
					dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
				}
			}
		}
	}

	cout << dp[h - 1][w - 1] << '\n';
}
