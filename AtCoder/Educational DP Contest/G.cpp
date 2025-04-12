#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> deg(n);
	vector<vector<int>> G(n);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		G[x].push_back(y);
		deg[y]++;
	}

	queue<int> q;
	for (int i = 0; i < n; i++)
		if (deg[i] == 0)
			q.push(i);

	vector<int> dp(n);
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : G[u]) {
			dp[v] = dp[u] + 1;
			deg[v]--;
			if (deg[v] == 0)
				q.push(v);
		}
	}

	cout << *max_element(dp.begin(), dp.end()) << '\n';
}
