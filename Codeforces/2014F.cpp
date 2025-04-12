#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, c;
		cin >> n >> c;
		vector<int> a(n);
		for (int &i : a)
			cin >> i;
		vector<vector<int>> G(n);
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}

		vector<vector<long long>> dp(n, vector<long long>(2));
		function<void(int, int)> DFS = [&](int u, int p) {
			dp[u][0] = 0;
			dp[u][1] = a[u];
			for (int v : G[u]) {
				if (v == p)
					continue;
				DFS(v, u);
				dp[u][0] += max(dp[v][0], dp[v][1]);
				dp[u][1] += max(dp[v][0], dp[v][1] - 2 * c);
			}
		};
		DFS(0, -1);
		cout << max(dp[0][0], dp[0][1]) << '\n';
	}
}
