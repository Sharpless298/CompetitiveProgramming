#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, m;
int dis[1000005];
int maze[1024][1024];
vector<pair<int, int>> G[1000005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int f(int x, int y) {
	return x * m + y;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;

	cin >> T;
	while (T--) {
		cin >> n >> m;

		for (int i = 0; i < n * m; i++)
			G[i].clear();

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> maze[i][j];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i + 1 < n) {
					G[f(i, j)].emplace_back(f(i + 1, j), maze[i + 1][j]);
					G[f(i + 1, j)].emplace_back(f(i, j), maze[i][j]);
				}
				if (j + 1 < m) {
					G[f(i, j)].emplace_back(f(i, j + 1), maze[i][j + 1]);
					G[f(i, j + 1)].emplace_back(f(i, j), maze[i][j]);
				}
			}
		}

		fill(dis, dis + n * m, INF);
		dis[0] = 0;
		pq.emplace(0, 0);
		while (!pq.empty()) {
			auto [d, u] = pq.top();
			pq.pop();

			if (dis[u] != d)
				continue;
			for (auto &[v, w] : G[u]) {
				if (dis[u] + w < dis[v]) {
					dis[v] = dis[u] + w;
					pq.emplace(dis[v], v);
				}
			}
		}

		cout << dis[n * m - 1] + maze[0][0] << '\n';
	}
}
