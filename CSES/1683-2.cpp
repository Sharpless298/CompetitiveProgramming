#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G, F;
vector<bool> vis;
vector<int> id;
stack<int> stk;
void DFS1(int u) {
	vis[u] = true;
	for (int v : G[u])
		if (!vis[v])
			DFS1(v);

	stk.push(u);
}

void DFS2(int u, int c) {
	vis[u] = true;
	for (int v : F[u])
		if (!vis[v])
			DFS2(v, c);
	id[u] = c;
}

int Kosaraju(int n) {
	vis.assign(n, false);
	for (int i = 0; i < n; i++)
		if (!vis[i])
			DFS1(i);

	int c = 0;
	vis.assign(n, false);
	id.resize(n);
	while (!stk.empty()) {
		if (!vis[stk.top()])
			DFS2(stk.top(), c++);
		stk.pop();
	}
	return c;
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

	cout << Kosaraju(n) << '\n';
	for (int i : id)
		cout << i + 1 << ' ';
	cout << '\n';
}
