struct TwoSAT {
	int n, time = 0, id = 0;
	vector<vector<int>> G;
	vector<bool> val;
	vector<int> tin, low, comp;
	stack<int> stk;

	TwoSAT(int _n) : n(_n) {
		G.assign(2 * n, vector<int>());
		val.assign(n, false);
		tin.assign(2 * n, -1), low.assign(2 * n, -1), comp.assign(2 * n, -1);
	}

	void add_clause(int x, int y) {
		G[x < n ? x + n : x - n].push_back(y);
		G[y < n ? y + n : y - n].push_back(x);
	}
	void DFS(int u) {
		tin[u] = low[u] = time++;
		stk.push(u);
		for (int v : G[u]) {
			if (comp[v] == -1) {
				if (tin[v] == -1)
					DFS(v);
				low[u] = min(low[u], low[v]);
			}
		}
		if (tin[u] == low[u]) {
			for (int v = -1; v != u; stk.pop())
				v = stk.top(), comp[v] = id;
			id++;
		}
	}
	bool solve() {
		for (int i = 0; i < 2 * n; i++)
			if (tin[i] == -1)
				DFS(i);
		for (int i = 0; i < n; i++) {
			if (comp[i] == comp[i + n])
				return false;
			val[i] = comp[i] < comp[i + n];
		}
		return true;
	}
};
