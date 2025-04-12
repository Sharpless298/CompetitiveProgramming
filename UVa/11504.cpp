#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<bool> vis;
void DFS(int u) {
	vis[u] = true;
	for (int v : G[u])
		if (!vis[v])
			DFS(v);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		G.assign(n, vector<int>());
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			G[u].push_back(v);
		}

		stack<int> stk;
		vis.assign(n, false);
		for (int i = 0; i < n; i++)
			if (!vis[i])
				DFS(i), stk.push(i);

		int ans = 0;
		vis.assign(n, false);
		while (!stk.empty()) {
			if (!vis[stk.top()])
				DFS(stk.top()), ans++;
			stk.pop();
		}

		cout << ans << '\n';
	}
}
