#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long int lli;

const lli INF = 4e18;

struct Edge {
	int u;
	lli c, p;
};

int n, m;
lli dis[100005];
vector<Edge> G[100005];

lli Dijkstra(int T, int A, int B) {
	priority_queue<pair<lli, int>, vector<pair<lli, int>>, greater<pair<lli, int>>> pq;

	fill(dis, dis + n, INF);
	dis[A] = 0;
	pq.emplace(0, A);
	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();

		if (dis[u] != d)
			continue;
		for (auto &[v, c, p] : G[u]) {
			lli w = c + (T - 1) * p;
			if (dis[u] + w < dis[v])
				dis[v] = dis[u] + w, pq.emplace(dis[v], v);
		}
	}

	return dis[B];
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, B, D;

	cin >> n >> m >> A >> B >> D;
	A--, B--;
	for (int i = 0; i < m; i++) {
		int n1, n2, c1, p1, c2, p2;

		cin >> n1 >> n2 >> c1 >> p1 >> c2 >> p2;
		n1--, n2--;
		G[n1].push_back({n2, c1, p1});
		G[n2].push_back({n1, c2, p2});
	}

	cout << min(Dijkstra(1, A, B) + Dijkstra(1, B, A), Dijkstra(D, A, B) + Dijkstra(D, B, A)) << '\n';
}
