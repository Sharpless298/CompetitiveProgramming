#include <bits/stdc++.h>
using namespace std;
struct LCA {
	int n, LOG;
	vector<int> depth;
	vector<vector<int>> G, ancestor;

	LCA(const vector<vector<int>> &graph, int root = 0) {
		G = graph;
		n = (int)G.size();
		LOG = __lg(n) + 1;
		depth.assign(n, 0);
		ancestor.assign(n, vector<int>(LOG, 0));
		DFS(root, root);
	}

	void DFS(int u, int p) {
		ancestor[u][0] = p;
		for (int i = 1; i < LOG; i++) {
			ancestor[u][i] = ancestor[ancestor[u][i - 1]][i - 1];
		}
		for (int v : G[u]) {
			if (v != p) {
				depth[v] = depth[u] + 1;
				DFS(v, u);
			}
		}
	}

	int query(int u, int v) {
		if (depth[u] < depth[v]) {
			swap(u, v);
		}
		for (int i = 0, k = depth[u] - depth[v]; i < LOG; i++) {
			if (k >> i & 1) {
				u = ancestor[u][i];
			}
		}
		if (u == v) {
			return u;
		}
		for (int i = LOG - 1; i >= 0; i--) {
			if (ancestor[u][i] != ancestor[v][i]) {
				u = ancestor[u][i];
				v = ancestor[v][i];
			}
		}
		return ancestor[u][0];
	}
};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;
	vector<vector<int>> G(n);
	for (int i = 1; i < n; i++) {
		int p;
		cin >> p;
		G[p].push_back(i);
		G[i].push_back(p);
	}
	LCA lca(G);
	while (q--) {
		int u, v;
		cin >> u >> v;
		cout << lca.query(u, v) << '\n';
	}
}
