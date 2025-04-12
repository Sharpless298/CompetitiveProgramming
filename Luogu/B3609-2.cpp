#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G, F, scc;
vector<bool> vis;
stack<int> stk;
void DFS1(int u) {
	vis[u] = true;
	for (int v : G[u])
		if (!vis[v])
			DFS1(v);
	stk.push(u);
}

void DFS2(int u) {
	vis[u] = true;
	for (int v : F[u])
		if (!vis[v])
			DFS2(v);
	scc.back().push_back(u);
}

void Kosaraju(int n) {
	vis.assign(n, false);
	for (int i = 0; i < n; i++)
		if (!vis[i])
			DFS1(i);

	vis.assign(n, false);
	while (!stk.empty()) {
		if (!vis[stk.top()])
			scc.push_back({}), DFS2(stk.top());
		stk.pop();
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	G.resize(n), F.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].push_back(v);
		F[v].push_back(u);
	}

	Kosaraju(n);

	for (auto &i : scc)
		sort(i.begin(), i.end());
	sort(scc.begin(), scc.end());

	cout << scc.size() << '\n';
	for (auto i : scc) {
		for (auto j : i)
			cout << j + 1 << ' ';
		cout << '\n';
	}
}
