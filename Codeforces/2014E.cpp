#include <bits/stdc++.h>
using namespace std;

void Dijkstra(int s, vector<vector<long long>> &d, vector<vector<pair<int, int>>> &G, vector<bool> horse) {
	priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>>
		pq;
	d[s][0] = 0;
	pq.push({0, s, 0});

	while (!pq.empty()) {
		auto [p, u, h] = pq.top();
		pq.pop();

		if (d[u][h] != p)
			continue;
		bool f = (h || horse[u]);
		for (auto [v, w] : G[u]) {
			w = f ? w / 2 : w;
			if (d[u][h] + w < d[v][f]) {
				d[v][f] = d[u][h] + w;
				pq.push({d[v][f], v, f});
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, m, h;
		cin >> n >> m >> h;
		vector<bool> horse(n);
		for (int i = 0; i < h; i++) {
			int u;
			cin >> u;
			u--;
			horse[u] = true;
		}

		vector<vector<pair<int, int>>> G(n);
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			u--, v--;
			G[u].push_back({v, w});
			G[v].push_back({u, w});
		}

		const long long INF = 0x3fffffffffffffff;
		vector<vector<long long>> d1(n, vector<long long>(2, INF));
		vector<vector<long long>> d2(n, vector<long long>(2, INF));
		Dijkstra(0, d1, G, horse);
		Dijkstra(n - 1, d2, G, horse);

		long long ans = INF;
		for (int i = 0; i < n; i++)
			ans = min(ans, max(min(d1[i][0], d1[i][1]), min(d2[i][0], d2[i][1])));

		cout << (ans == INF ? -1 : ans) << '\n';
	}
}
