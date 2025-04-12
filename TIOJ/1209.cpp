#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;

bool f, vis[40005];
int n, m, color[40005];
vector<int> G[40005];

void BFS(int u) {
	int v;
	queue<int> q;

	q.push(u);
	vis[u] = true;
	color[u] = 1;

	while (!q.empty()) {
		v = q.front(), q.pop();

		for (int i : G[v]) {
			if (color[v] == color[i]) {
				f = false;
				return;
			}
			if (!vis[i])
				q.push(i), vis[i] = true, color[i] = !color[v];
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> n >> m && n) {
		f = true;
		memset(vis, 0, sizeof(vis));
		fill(color, color + 40005, -INF);
		for (int i = 0; i < 40005; i++)
			G[i].clear();

		for (int i = 0, u, v; i < m; i++) {
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}

		BFS(1);

		if (f)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}
