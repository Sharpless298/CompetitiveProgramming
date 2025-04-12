#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int &i : a)
			cin >> i;

		int dp[n][2][2];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 2; j++)
				for (int k = 0; k < 2; k++)
					dp[i][j][k] = 0x3f3f3f3f;
		dp[0][0][0] = a[0];
		for (int i = 1; i < n; i++) {
			dp[i][0][0] = min(dp[i - 1][1][0], dp[i - 1][1][1]) + a[i];
			dp[i][0][1] = dp[i - 1][0][0] + a[i];
			dp[i][1][0] = min(dp[i - 1][0][0], dp[i - 1][0][1]);
			dp[i][1][1] = dp[i - 1][1][0];
		}
		cout << min({dp[n - 1][0][0], dp[n - 1][0][1], dp[n - 1][1][0], dp[n - 1][1][1]}) << '\n';
	}
}
