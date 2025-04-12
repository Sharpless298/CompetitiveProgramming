#include <bits/stdc++.h>
using namespace std;

struct TwoSAT {
	int n;
	vector<vector<int>> G;

	TwoSAT(int _n) : n(_n) {
		G.assign(2 * n, vector<int>());
	}
	void add_clause(int x, int y) {
		G[x < n ? x + n : x - n].push_back(y);
		G[y < n ? y + n : y - n].push_back(x);
	}

	int time = 0, id = 0;
	vector<bool> val;
	vector<int> tin, low, comp;
	stack<int> stk;
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
		val.assign(n, false);
		tin.assign(2 * n, -1), low.assign(2 * n, -1), comp.assign(2 * n, -1);
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

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector a(3, vector<int>(n));
		for (auto &i : a)
			for (auto &j : i)
				cin >> j;

		TwoSAT solver(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = j + 1; k < 3; k++) {
					int x = (a[j][i] > 0 ? a[j][i] - 1 : -a[j][i] - 1 + n);
					int y = (a[k][i] > 0 ? a[k][i] - 1 : -a[k][i] - 1 + n);
					solver.add_clause(x, y);
				}
			}
		}

		cout << (solver.solve() ? "YES\n" : "NO\n");
	}
}
