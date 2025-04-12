#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<pair<int, int>> dp;
void DFS(int u, int p) {
	dp[u].first = (int)G[u].size();

	int mx1 = -1, mx2 = -1;
	for (int v : G[u]) {
		if (v == p)
			continue;

		DFS(v, u);
		dp[u].first = max(dp[u].first, dp[v].first + (int)G[u].size() - 2);
		if (dp[v].first > mx1)
			mx2 = mx1, mx1 = dp[v].first;
		else if (dp[v].first > mx2)
			mx2 = dp[v].first;
	}

	dp[u].second = mx1 + mx2 + (int)G[u].size() - 4;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		G.assign(n, vector<int>());
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}

		dp.resize(n);
		DFS(0, 0);

		int ans = 0;
		for (int i = 0; i < n; i++)
			ans = max({ans, dp[i].first, dp[i].second});
		cout << ans << '\n';
	}
}
