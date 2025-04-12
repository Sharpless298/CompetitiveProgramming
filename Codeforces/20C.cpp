#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

typedef long long int lli;

const lli INF = 1e18;

int n, m;
int parent[100005];
lli dis[100005];
vector<int> ans;
vector<pair<int, int>> G[100005];

void Find(int x) {
	if (x != 1)
		Find(parent[x]);
	cout << x << ' ';
}

void Dijkstra() {
	priority_queue<pair<lli, int>, vector<pair<lli, int>>, greater<pair<lli, int>>> pq;
	for (int i = 1; i <= n; i++)
		dis[i] = INF, parent[i] = i;

	dis[1] = 0;
	pq.emplace(0, 1);

	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();

		if (dis[u] != d)
			continue;
		for (auto &[v, w] : G[u]) {
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				pq.emplace(dis[v], v);
				parent[v] = u;
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w;
		G[u].emplace_back(v, w);
		G[v].emplace_back(u, w);
	}

	Dijkstra();

	if (dis[n] == INF)
		cout << -1 << '\n';
	else {
		Find(n);
		cout << '\n';
	}
}
