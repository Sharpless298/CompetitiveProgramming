#include <iostream>
using namespace std;

typedef long long int lli;

int n, m, dp[32][32];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	dp[0][0] = 1;
	for (int i = 1; i < m; i++)
		for (int j = 0; j < n; j++)
			dp[i][j] = dp[i - 1][(j - 1 + n) % n] + dp[i - 1][(j + 1) % n];
	dp[m][0] = dp[m - 1][n - 1] + dp[m - 1][1];

	cout << dp[m][0] << '\n';
}
