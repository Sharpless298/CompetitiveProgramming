#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

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

	vector<int> f(n), g(n), ans(n);
	function<void(int, int)> DFS = [&](int u, int p) {
		for (int v : G[u]) {
			if (v != p) {
				DFS(v, u);
				if (f[v] + 1 > f[u]) {
					g[u] = f[u];
					f[u] = f[v] + 1;
				} else if (f[v] + 1 > g[u]) {
					g[u] = f[v] + 1;
				}
			}
		}
	};
	function<void(int, int, int)> DFS2 = [&](int u, int p, int to_p) {
		ans[u] = max(f[u], to_p);
		for (int v : G[u]) {
			if (v != p) {
				if (f[v] + 1 == f[u]) {
					DFS2(v, u, max(to_p, g[u]) + 1);
				} else {
					DFS2(v, u, ans[u] + 1);
				}
			}
		}
	};
	DFS(0, 0);
	DFS2(0, 0, 0);
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " \n"[i + 1 == n];
	}
}
