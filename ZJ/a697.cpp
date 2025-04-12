#include <iostream>
using namespace std;

const int MOD = 1e6 + 7;

int n, m, ary[105], dp[105][105];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> ary[i];

	for (int i = 0; i <= ary[1]; i++)
		dp[1][i] = 1;

	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int k = 0; k <= min(ary[i], j); k++)
				dp[i][j] += dp[i - 1][j - k], dp[i][j] %= MOD;

	cout << dp[n][m] << '\n';
}
