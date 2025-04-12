#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, s1, s2;
		cin >> n >> s1 >> s2;
		s1--, s2--;
		vector<vector<int>> G(n), F(n);
		set<pair<int, int>> E;
		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			G[u].push_back(v);
			G[v].push_back(u);
			E.insert({u, v});
			E.insert({v, u});
		}
		vector<bool> good(n);
		cin >> m;
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			F[u].push_back(v);
			F[v].push_back(u);
			if (E.find({u, v}) != E.end())
				good[u] = good[v] = true;
		}

		vector<vector<int>> dist(n, vector<int>(n, 0x3f3f3f3f));
		set<pair<int, pair<int, int>>> s;
		dist[s1][s2] = 0;
		s.insert({0, {s1, s2}});
		while (!s.empty()) {
			auto [u, v] = s.begin()->second;
			s.erase(s.begin());

			for (int a : G[u]) {
				for (int b : F[v]) {
					int w = abs(a - b);
					if (dist[u][v] + w < dist[a][b]) {
						s.erase({dist[a][b], {a, b}});
						dist[a][b] = dist[u][v] + w;
						s.insert({dist[a][b], {a, b}});
					}
				}
			}
		}

		int ans = 0x3f3f3f3f;
		for (int i = 0; i < n; i++)
			if (good[i])
				ans = min(ans, dist[i][i]);
		cout << (ans == 0x3f3f3f3f ? -1 : ans) << '\n';
	}
}
