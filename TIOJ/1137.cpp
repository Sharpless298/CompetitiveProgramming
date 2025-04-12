#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<int> dfn, low, ap;
int timestamp = 1;
void DFS(int u, int p) {
	int cnt = 0;
	dfn[u] = low[u] = timestamp++;
	bool f = false;
	for (int v : G[u]) {
		if (v == p)
			continue;
		if (!dfn[v]) {
			DFS(v, u), cnt++;
			if (dfn[u] <= low[v])
				f = true;
			low[u] = min(low[u], low[v]);
		}
		low[u] = min(low[u], dfn[v]);
	}
	if (u == p && cnt < 2)
		f = false;
	if (f)
		ap.push_back(u);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		G.assign(n, vector<int>());
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		ap.clear();
		dfn.assign(n, 0), low.assign(n, 0);
		DFS(0, 0);

		cout << ap.size() << '\n';
		if (ap.empty())
			cout << 0 << '\n';
		else {
			sort(ap.begin(), ap.end());
			for (int i : ap)
				cout << i + 1 << ' ';
			cout << '\n';
		}
	}
}
