#include <bits/stdc++.h>
using namespace std;

int timer = 0, cnt;
vector<vector<int>> G;
vector<bool> f;
vector<int> id, low, ans;
stack<int> stk;

void DFS(int u) {
	f[u] = true;
	id[u] = low[u] = ++timer;
	stk.push(u);
	for (int v : G[u]) {
		if (!id[v])
			DFS(v), low[u] = min(low[u], low[v]);
		else if (f[v])
			low[u] = min(low[u], id[v]);
	}
	if (id[u] == low[u]) {
		for (int v = -1; v != u; stk.pop())
			v = stk.top(), f[v] = false, ans[v] = cnt;
		cnt++;
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

	ans.assign(n, 0), f.assign(n, 0), id.assign(n, 0), low.assign(n, 0);
	for (int i = 0; i < n; i++)
		if (!id[i])
			DFS(i);

	cout << cnt << '\n';
	for (int i : ans)
		cout << i + 1 << ' ';
	cout << '\n';
}
