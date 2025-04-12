#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long int lli;

int n, m;
lli a[200005], dis[200005];
vector<pair<int, lli>> G[200005];

void Dijkstra() {
	priority_queue<pair<lli, int>, vector<pair<lli, int>>, greater<pair<lli, int>>> pq;

	for (int i = 0; i < n; i++) {
		dis[i] = a[i];
		pq.emplace(dis[i], i);
	}
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

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		lli w;

		cin >> u >> v >> w;
		u--, v--, w *= 2;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}

	for (int i = 0; i < n; i++)
		cin >> a[i];
	Dijkstra();

	for (int i = 0; i < n; i++)
		cout << dis[i] << ' ';
	cout << '\n';
}
