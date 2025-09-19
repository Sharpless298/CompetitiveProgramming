#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int v[] = {0, 1, 5, 10, 25, 50};
	vector<vector<int>> dp(6, vector<int>(7490));
	dp[0][0] = 1;
	for (int i = 1; i < 6; i++) {
		for (int j = 0; j < 7490; j++) {
			for (int k = 0; k <= j / v[i]; k++) {
				dp[i][j] += dp[i - 1][j - v[i] * k];
			}
		}
	}

	int n;
	while (cin >> n) {
		cout << dp[5][n] << '\n';
	}
}
