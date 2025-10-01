#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<long double> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	vector<vector<long double>> dp(n + 1, vector<long double>(n + 1));
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j] * (1 - p[i - 1]);
			} else {
				dp[i][j] = dp[i - 1][j] * (1 - p[i - 1]) + dp[i - 1][j - 1] * p[i - 1];
			}
		}
	}

	long double ans = 0;
	for (int i = n / 2 + 1; i <= n; i++) {
		ans += dp[n][i];
	}
	cout << fixed << setprecision(10) << ans << '\n';
}
