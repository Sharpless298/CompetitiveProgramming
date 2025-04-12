#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		string a, b, c;
		cin >> a >> b >> c;

		int n = (int)a.size(), m = (int)b.size();
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0x3f3f3f3f));

		dp[0][0] = 0;
		for (int i = 0; i < n; i++)
			dp[i + 1][0] = dp[i][0] + (a[i] != c[i]);
		for (int i = 0; i < m; i++)
			dp[0][i + 1] = dp[0][i] + (b[i] != c[i]);
		for (int i = 1; i <= (int)a.size(); i++)
			for (int j = 1; j <= (int)b.size(); j++)
				dp[i][j] = min(dp[i - 1][j] + (a[i - 1] != c[i + j - 1]), dp[i][j - 1] + (b[j - 1] != c[i + j - 1]));

		cout << dp[a.size()][b.size()] << '\n';
	}
}
