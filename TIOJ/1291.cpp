#include <iostream>
using namespace std;

const int MOD = 1e6;

int n, m, dp[205][205], ans;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	dp[0][0] = 1;
	for (int i = 1; i <= 200; i++)
		for (int j = 1; j <= 200; j++)
			dp[i][j] = (dp[i][j - 1] * i + dp[i - 1][j - 1]) % MOD;

	while (cin >> n >> m && n) {
		ans = 0;
		for (int i = 1; i <= n; i++)
			ans = (ans + dp[i][m]) % MOD;

		cout << ans << '\n';
	}
}
