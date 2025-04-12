#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

bool vis[200005];
int node, depth[200005];
vector<int> G[200005];

void DFS(int d, int u, int f) {
	vis[u] = true;
	depth[u] = d;
	for (int &v : G[u]) {
		if (v != f) {
			if (vis[v]) {
				if (node == 0x3f3f3f3f || depth[v] < depth[node])
					node = v;
				return;
			}
			DFS(d + 1, v, u);
		}
	}
}

int BFS(pair<int, int> u) {
	queue<pair<int, int>> q;

	q.push(u);
	vis[u.first] = true;

	while (!q.empty()) {
		u = q.front(), q.pop();

		if (u.first == node)
			return u.second;
		for (int &v : G[u.first]) {
			if (!vis[v]) {
				vis[v] = true;
				q.push({v, u.second + 1});
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, a, b, T;

	cin >> T;
	while (T--) {
		node = 0x3f3f3f3f;
		memset(vis, 0, sizeof(vis));
		memset(depth, 0, sizeof(depth));
		for (int i = 0; i < 200005; i++)
			G[i].clear();

		cin >> n >> a >> b;
		for (int i = 0, u, v; i < n; i++) {
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}

		DFS(0, b, 0);

		memset(vis, 0, sizeof(vis));
		if (node != 0x3f3f3f3f && depth[node] < BFS({a, 0}))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
