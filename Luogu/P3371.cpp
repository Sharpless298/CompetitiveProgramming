#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = INT_MAX;

int n, m, s;
int dis[10005];
vector<pair<int, int>> G[10005];

void Dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	fill(dis, dis + n, INF);
	dis[s] = 0;
	pq.emplace(dis[s], s);

	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();

		if (dis[u] != d)
			continue;
		for (auto &[v, w] : G[u])
			if (dis[u] + w < dis[v])
				dis[v] = dis[u] + w, pq.emplace(dis[v], v);
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> s;
	s--;
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w;
		u--, v--;
		G[u].push_back({v, w});
	}

	Dijkstra();

	for (int i = 0; i < n; i++)
		cout << dis[i] << ' ';
	cout << '\n';
}
