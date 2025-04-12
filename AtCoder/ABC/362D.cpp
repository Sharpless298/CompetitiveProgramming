#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long int lli;

const lli INF = 4e18;

int n, m;
lli a[200005], dis[200005];
vector<pair<int, lli>> G[200005];
priority_queue<pair<lli, int>, vector<pair<lli, int>>, greater<pair<lli, int>>> pq;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++) {
		int u, v;
		lli w;

		cin >> u >> v >> w;
		u--, v--;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}

	fill(dis, dis + n, INF);
	dis[0] = a[0];
	pq.emplace(dis[0], 0);
	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();

		if (dis[u] != d)
			continue;
		for (auto &[v, w] : G[u])
			if (dis[u] + w + a[v] < dis[v])
				dis[v] = dis[u] + w + a[v], pq.emplace(dis[v], v);
	}

	for (int i = 1; i < n; i++)
		cout << dis[i] << ' ';
	cout << '\n';
}
