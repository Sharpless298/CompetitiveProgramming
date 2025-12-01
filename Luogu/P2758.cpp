#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string A, B;
	cin >> A >> B;

	int n = (int)A.size(), m = (int)B.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0x3f3f3f3f));
	for (int i = 0; i <= n; i++) {
		dp[i][0] = i;
	}
	for (int i = 0; i <= m; i++) {
		dp[0][i] = i;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i + 1][j + 1] = min({dp[i][j + 1] + 1, dp[i + 1][j] + 1, dp[i][j] + (A[i] != B[j])});
		}
	}

	cout << dp[n][m] << '\n';
}
