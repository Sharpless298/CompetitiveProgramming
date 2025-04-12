#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i + 1; j++)
			cin >> a[i][j];

	vector<vector<int>> dp(n, vector<int>(n));
	dp[0][0] = a[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (j == 0)
				dp[i][j] = dp[i - 1][j] + a[i][j];
			else if (j == i)
				dp[i][j] = dp[i - 1][j - 1] + a[i][j];
			else
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
		}
	}

	cout << *max_element(dp[n - 1].begin(), dp[n - 1].end()) << '\n';
}
