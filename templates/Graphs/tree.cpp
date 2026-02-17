struct LCA {
	int n, LOG, timer;
	vector<int> depth, tin, tout;
	vector<vector<int>> G, ancestor;

	LCA(const vector<vector<int>> &graph, int root = 0) {
		G = graph;
		n = (int)G.size();
		LOG = __lg(n) + 1;
		timer = 0;
		tin.assign(n, 0);
		tout.assign(n, 0);
		depth.assign(n, 0);
		ancestor.assign(n, vector<int>(LOG, 0));
		DFS(root, root);
	}

	void DFS(int u, int p) {
		tin[u] = timer++;
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
		tout[u] = timer;
	}

	bool is_ancestor(int u, int v) {
		return tin[u] <= tin[v] && tout[u] >= tout[v];
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
