#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>> G(n);
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;

			G[u].push_back(v);
			G[v].push_back(u);
		}

		if (n == 2) {
			cout << "NO\n";
			continue;
		}

		int w = -1;
		vector<pair<int, int>> ans;
		vector<int> vis(n);
		function<void(int)> DFS = [&](int u) {
			if (G[u].size() == 2) {
				w = u;
				return;
			}

			vis[u] = true;
			for (int v : G[u]) {
				if (vis[v]) {
					continue;
				}
				DFS(v);
			}
		};
		function<void(int, int)> DFS2 = [&](int u, int c) {
			vis[u] = true;
			for (int v : G[u]) {
				if (vis[v]) {
					continue;
				}
				ans.push_back(c ? make_pair(u, v) : make_pair(v, u));
				DFS2(v, c ^ 1);
			}
		};
		DFS(0);
		if (w == -1) {
			cout << "NO\n";
			continue;
		}
		ans.push_back(make_pair(G[w][0], w));
		ans.push_back(make_pair(w, G[w][1]));
		vis.assign(n, false);
		vis[w] = true;
		DFS2(G[w][0], 1);
		DFS2(G[w][1], 0);

		cout << "YES\n";
		for (pair<int, int> &p : ans) {
			cout << p.first + 1 << ' ' << p.second + 1 << '\n';
		}
	}
}
