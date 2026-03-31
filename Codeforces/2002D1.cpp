#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		vector<vector<int>> G(n + 1);
		G[0].push_back(1);
		for (int i = 2; i <= n; i++) {
			int p;
			cin >> p;
			G[p].push_back(i);
		}

		vector<int> order;
		function<void(int, int)> DFS = [&](int u, int p) {
			order.push_back(u);
			for (int v : G[u]) {
				if (v != p) {
					DFS(v, u);
				}
			}
		};
		DFS(0, -1);

		vector<int> pos(n + 1);
		for (int i = 0; i <= n; i++) {
			pos[order[i]] = i;
		}
		vector<int> up(n + 1);
		for (int i = 1; i <= n; i++) {
			up[pos[i]] = pos[i >> 1];
		}

		vector<int> p(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> p[i];
		}

		int cnt = 0;
		auto update = [&](int i, int c) {
			if (p[up[i]] == (p[i] >> 1)) {
				cnt += c;
			}
		};
		for (int i = 1; i <= n; i++) {
			update(i, 1);
		}

		while (q--) {
			int x, y;
			cin >> x >> y;

			vector<int> v;
			v.push_back(x);
			v.push_back(y);
			if (G[order[x]].size()) {
				v.push_back(pos[G[order[x]][0]]);
				v.push_back(pos[G[order[x]][1]]);
			}
			if (G[order[y]].size()) {
				v.push_back(pos[G[order[y]][0]]);
				v.push_back(pos[G[order[y]][1]]);
			}
			sort(v.begin(), v.end());
			v.resize(unique(v.begin(), v.end()) - v.begin());

			for (int i : v) {
				if (1 <= i && i <= n) {
					update(i, -1);
				}
			}
			swap(p[x], p[y]);
			for (int i : v) {
				if (1 <= i && i <= n) {
					update(i, 1);
				}
			}
			cout << (cnt == n ? "YES\n" : "NO\n");
		}
	}
}
