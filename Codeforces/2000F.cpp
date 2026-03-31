#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<vector<int>> cost(n);
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			cost[i].push_back(0);
			while (true) {
				if (a > b) {
					swap(a, b);
				}
				if (b == 1) {
					int tmp = cost[i].back();
					cost[i].push_back(1 << 30);
					cost[i].push_back(tmp + 1);
					break;
				}
				cost[i].push_back(cost[i].back() + a);
				b--;
			}
		}

		vector<int> dp(2 * k + 1, 1 << 30);
		dp[0] = 0;
		for (int i = 0; i < n; i++) {
			auto nxt = dp;
			for (int j = 0; j < k; j++) {
				for (int l = 1; l < min(2 * k - j + 1, (int)cost[i].size()); l++) {
					if (cost[i][l] != 1 << 30) {
						nxt[j + l] = min(nxt[j + l], dp[j] + cost[i][l]);
					}
				}
			}
			dp = nxt;
		}
		int ans = 1 << 30;
		for (int i = k; i <= 2 * k; i++) {
			ans = min(ans, dp[i]);
		}
		cout << (ans == 1 << 30 ? -1 : ans) << '\n';
	}
}
