#include <bits/stdc++.h>
using namespace std;

int timestamp = 0;
vector<int> dfn, low, E;
vector<vector<int>> G, bcc;
stack<int> stk;
void DFS(int u, int p) {
	dfn[u] = low[u] = ++timestamp;
	stk.push(u);

	int cnt = 0;
	for (int idx : G[u]) {
		int v = E[idx];
		if (!dfn[v]) {
			DFS(v, idx ^ 1), cnt++;
			low[u] = min(low[u], low[v]);
			if (low[v] >= dfn[u]) {
				bcc.push_back({});
				for (int w = -1; w != v; stk.pop())
					w = stk.top(), bcc.back().push_back(w);
				bcc.back().push_back(u);
			}
		} else if (idx != p)
			low[u] = min(low[u], dfn[v]);
	}
	if (p == -1 && cnt == 0)
		bcc.push_back({u});
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	G.assign(n, vector<int>());
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].push_back((int)E.size());
		E.push_back(v);
		G[v].push_back((int)E.size());
		E.push_back(u);
	}

	dfn.assign(n, 0), low.assign(n, 0);
	for (int i = 0; i < n; i++) {
		if (dfn[i])
			continue;
		while (!stk.empty())
			stk.pop();
		DFS(i, -1);
	}

	cout << bcc.size() << '\n';
	for (auto i : bcc) {
		cout << i.size();
		for (int j : i)
			cout << ' ' << j + 1;
		cout << '\n';
	}
}
