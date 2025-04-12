#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool vis[100005], f[100005];
int V, E, Case, k;
vector<int> G[100005];

int BFS(int u) {
	int v, cnt;
	queue<int> q;

	cnt = 1;
	vis[u] = true;
	q.push(u);

	while (!q.empty()) {
		v = q.front(), q.pop();

		for (int i : G[v])
			if (!vis[i])
				cnt++, vis[i] = true, q.push(i);
	}

	return cnt;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int u, v;

	while (cin >> u >> v) {
		V = E = 0;
		memset(f, 0, sizeof(f));
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < 100005; i++)
			G[i].clear();

		if (u < 0 && v < 0)
			break;
		if (u == 0 && v == 0) {
			cout << "Case " << ++Case << " is a tree.\n";
			continue;
		}

		if (!f[u])
			V++, f[u] = true;
		if (!f[v])
			V++, f[v] = true;
		E++;
		G[u].push_back(v), G[v].push_back(u);
		k = u;
		while (cin >> u >> v && u) {
			if (!f[u])
				V++, f[u] = true;
			if (!f[v])
				V++, f[v] = true;
			E++;
			G[u].push_back(v), G[v].push_back(u);
			k = u;
		}

		if (V == E + 1 && BFS(k) == V)
			cout << "Case " << ++Case << " is a tree.\n";
		else
			cout << "Case " << ++Case << " is not a tree.\n";
	}
}
