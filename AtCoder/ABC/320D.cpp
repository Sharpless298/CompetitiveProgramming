#include <iostream>
#include <vector>
using namespace std;

vector<bool> vis;
vector<pair<long long, long long>> p;
vector<vector<pair<int, pair<int, int>>>> G;
void DFS(int u) {
	for (auto v : G[u]) {
		if (vis[v.first])
			continue;

		vis[v.first] = true;
		p[v.first] = {p[u].first + v.second.first, p[u].second + v.second.second};
		DFS(v.first);
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	G.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		a--, b--;

		G[a].push_back({b, {x, y}});
		G[b].push_back({a, {-x, -y}});
	}

	p.resize(n), vis.resize(n);
	p[0] = {0, 0}, vis[0] = true;
	DFS(0);

	for (int i = 0; i < n; i++) {
		if (vis[i])
			cout << p[i].first << ' ' << p[i].second << '\n';
		else
			cout << "undecidable\n";
	}
}
