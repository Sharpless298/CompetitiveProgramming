#include <bits/stdc++.h>
using namespace std;

const int MOD = 80112002;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> in(n), out(n);
	vector<vector<int>> G(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].push_back(v);
		in[v]++;
		out[u]++;
	}

	queue<int> q;
	vector<int> dp(n);
	for (int i = 0; i < n; i++) {
		if (in[i] == 0) {
			dp[i] = 1;
			q.push(i);
		}
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : G[u]) {
			in[v]--;
			dp[v] = (dp[v] + dp[u]) % MOD;;
			if (in[v] == 0) {
				q.push(v);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (out[i] == 0) {
			ans = (ans + dp[i]) % MOD;
		}
	}
	cout << ans << '\n';
}
