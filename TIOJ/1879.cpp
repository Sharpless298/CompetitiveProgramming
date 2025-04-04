#include <bits/stdc++.h>
using namespace std;

int timestamp = 1;
vector<int> dfn, low, E;
vector<vector<int>> G, bcc;
stack<int> stk;
void DFS(int u, int p) {
	dfn[u] = low[u] = timestamp++;
	stk.push(u);

	for (int idx : G[u]) {
		int v = E[idx];
		if (!dfn[v]) {
			DFS(v, idx ^ 1);
			low[u] = min(low[u], low[v]);
		}
		else if (idx != p)
			low[u] = min(low[u], dfn[v]);
	}

	if (dfn[u] == low[u]) {
		bcc.push_back({});
		while (stk.top() != u) {
			bcc.back().push_back(stk.top());
			stk.pop();
		}
		bcc.back().push_back(stk.top());
		stk.pop();
	}
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
		G[u].push_back((int)E.size());
		E.push_back(v);
		G[v].push_back((int)E.size());
		E.push_back(u);
	}

	dfn.assign(n, 0), low.assign(n, 0);

	DFS(0, -1);
	for (auto &i : bcc) sort(i.begin(), i.end());
	sort(bcc.begin(), bcc.end());

	for (int i = 0; i < (int)bcc.size(); i++) {
		cout << i + 1 << ':';
		for (auto j : bcc[i]) cout << ' ' << j;
		cout << '\n';
	}
}
