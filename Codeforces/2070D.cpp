#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> depth(n), parent(n);
		vector<vector<int>> G(n);
		for (int i = 1; i < n; i++) {
			int u;
			cin >> u;
			u--;
			depth[i] = depth[u] + 1;
			G[u].push_back(i);
			parent[i] = u;
		}

		queue<int> q;
		vector<int> dp(n), all(n);
		dp[0] = 1;
		all[0] = 1;
		for (int u : G[0]) {
			dp[u] = 1;
			all[1]++;
			for (int v : G[u])
				q.push(v);
		}

		while (!q.empty()) {
			int u = q.front();
			q.pop();

			dp[u] = (all[depth[u] - 1] - dp[parent[u]]) % MOD;
			all[depth[u]] = (all[depth[u]] + all[depth[u] - 1] - dp[parent[u]]) % MOD;
			for (int v : G[u])
				q.push(v);
		}

		int ans = 0;
		for (int i : all)
			ans = (ans + i) % MOD;
		ans = ((ans % MOD) + MOD) % MOD;
		cout << ans << '\n';
	}
}
