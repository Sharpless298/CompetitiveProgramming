#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> G(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].push_back(v);
	}

	vector<bool> vis(n, false);
	function<void(int)> DFS = [&](int u) {
		vis[u] = true;
		for (int v : G[u])
			if (!vis[v])
				DFS(v);
	};
	stack<int> stk;
	for (int i = 0; i < n; i++)
		if (!vis[i])
			DFS(i), stk.push(i);

	int ans = 0;
	fill(vis.begin(), vis.end(), false);
	while (!stk.empty()) {
		if (!vis[stk.top()])
			DFS(stk.top()), ans++;
		stk.pop();
	}
	cout << ans << '\n';
}
