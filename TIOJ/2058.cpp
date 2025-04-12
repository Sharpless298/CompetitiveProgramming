#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long int lli;

const lli INF = 4e18;

int n, m, A, B;
lli dis[100005], dis2[100005];
vector<pair<int, lli>> G[100005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;

	cin >> T;
	while (T--) {
		cin >> n >> m >> A >> B;
		for (int i = 0; i < n; i++)
			G[i].clear();
		for (int i = 0, u, v, w; i < m; i++) {
			cin >> u >> v >> w;
			G[u].push_back({v, w});
		}

		priority_queue<pair<lli, int>, vector<pair<lli, int>>, greater<pair<lli, int>>> pq;
		for (int i = 0; i < n; i++)
			dis[i] = dis2[i] = INF;
		dis[A] = 0;
		pq.push({0, A});
		while (!pq.empty()) {
			auto [d, u] = pq.top();
			pq.pop();

			if (dis2[u] < d)
				continue;
			for (auto &[v, w] : G[u]) {
				lli tmp = d + w;
				if (tmp < dis[v])
					swap(tmp, dis[v]), pq.push({dis[v], v});
				if (tmp < dis2[v] && tmp != dis[v])
					dis2[v] = tmp, pq.push({dis2[v], v});
			}
		}

		cout << dis2[B] - dis[B] << '\n';
	}
}
