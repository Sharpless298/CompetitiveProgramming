#include <bits/stdc++.h>
using namespace std;

long long dp[2][201][201][2];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	const int MOD = 1e9 + 7;

	int n, m, k;
	cin >> n >> m >> k;
	string a, b;
	cin >> a >> b;
	a = " " + a;
	b = " " + b;
	dp[0][0][0][0] = 1;
	dp[1][0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int p = 1; p <= k; p++) {
				if (a[i] == b[j]) {
					dp[i & 1][j][p][1] = (dp[(i - 1) & 1][j - 1][p][1] + dp[(i - 1) & 1][j - 1][p - 1][0] +
										  dp[(i - 1) & 1][j - 1][p - 1][1]) %
										 MOD;
					dp[i & 1][j][p][0] = (dp[(i - 1) & 1][j][p][1] + dp[(i - 1) & 1][j][p][0]) % MOD;
				} else {
					dp[i & 1][j][p][1] = 0;
					dp[i & 1][j][p][0] = (dp[(i - 1) & 1][j][p][1] + dp[(i - 1) & 1][j][p][0]) % MOD;
				}
			}
		}
	}
	cout << (dp[n & 1][m][k][0] + dp[n & 1][m][k][1]) % MOD << '\n';
}
