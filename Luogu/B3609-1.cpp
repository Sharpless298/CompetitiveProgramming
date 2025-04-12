#include <bits/stdc++.h>
using namespace std;

int timer = 0, id = 0;
vector<vector<int>> G, scc;
vector<int> scc_id;
vector<int> dfn, low;
stack<int> stk;

void DFS(int u) {
	dfn[u] = low[u] = ++timer;
	stk.push(u);
	for (int v : G[u]) {
		if (scc_id[v] == -1) {
			if (!dfn[v])
				DFS(v);
			low[u] = min(low[u], low[v]);
		}
	}
	if (dfn[u] == low[u]) {
		scc.push_back({});
		for (int v = -1; v != u; stk.pop())
			v = stk.top(), scc.back().push_back(v), scc_id[v] = id;
		id++;
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	G.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].push_back(v);
	}

	dfn.assign(n, 0), low.assign(n, 0), scc_id.assign(n, -1);
	for (int i = 0; i < n; i++)
		if (!dfn[i])
			DFS(i);

	for (auto &i : scc)
		sort(i.begin(), i.end());
	sort(scc.begin(), scc.end());

	cout << scc.size() << '\n';
	for (int i = 0; i < (int)scc.size(); i++)
		for (int j = 0; j < (int)scc[i].size(); j++)
			cout << scc[i][j] + 1 << " \n"[j + 1 == (int)scc[i].size()];
}
