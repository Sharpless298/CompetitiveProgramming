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
		map<int, int> cnt;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			cnt[x]++;
		}
		vector<int> a;
		for (auto p : cnt)
			a.push_back(p.second);

		n = (int)a.size();
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0x3f3f3f3f));
		dp[0][0] = 0;
		for (int i = 1; i <= n; i++) {
			dp[i] = dp[i - 1];
			for (int j = 1; j <= n; j++)
				if (dp[i - 1][j - 1] + a[i - 1] <= i - j)
					dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + a[i - 1]);
		}

		int ans = 0x3f3f3f3f;
		for (int i = 0; i <= n; i++)
			if (dp[n][i] != 0x3f3f3f3f)
				ans = min(ans, n - i);
		cout << ans << '\n';
	}
}
