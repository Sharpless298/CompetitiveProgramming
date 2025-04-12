#include <bits/stdc++.h>
using namespace std;

int ans = 0;
vector<int> id;
vector<vector<int>> G;
int BFS(int u) {
	queue<int> q;
	array<int, 2> cnt;
	cnt[0] = cnt[1] = 0;
	q.push(u);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		cnt[id[v]]++;
		for (int w : G[v]) {
			if (id[w] == -1) {
				id[w] = id[v] ^ 1;
				q.push(w);
			} else if (id[w] == id[v])
				return false;
		}
	}
	ans += min(cnt[0], cnt[1]);
	return true;
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
		G[u].push_back(v);
		G[v].push_back(u);
	}

	id.assign(n, -1);
	for (int i = 0; i < n; i++) {
		if (id[i] == -1) {
			id[i] = 0;
			if (!BFS(i)) {
				cout << 0 << '\n';
				return 0;
			}
		}
	}
	cout << ans << '\n';
}
