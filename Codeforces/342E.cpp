#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;

int lgN;
vector<int> depth;
vector<vector<int>> ac;
void DFS(int u, int p) {
	for (int v : G[u]) {
		if (v == p)
			continue;
		depth[v] = depth[u] + 1;
		ac[v][0] = u;
		for (int i = 1; i <= lgN; i++)
			ac[v][i] = ac[ac[v][i - 1]][i - 1];
		DFS(v, u);
	}
}

int LCA(int u, int v) {
	if (depth[u] < depth[v])
		swap(u, v);
	int d = depth[u] - depth[v];
	for (int i = 0; i <= lgN; i++)
		if (d & (1 << i))
			u = ac[u][i];
	if (u == v)
		return u;
	for (int i = lgN; i >= 0; i--)
		if (ac[u][i] != ac[v][i])
			u = ac[u][i], v = ac[v][i];
	return ac[u][0];
}

int dist(int u, int v) {
	return depth[u] + depth[v] - 2 * depth[LCA(u, v)];
}

vector<bool> vis;
vector<int> sz, parent;
int find_size(int u, int p) {
	sz[u] = 1;
	for (int v : G[u]) {
		if (v == p || vis[v])
			continue;
		sz[u] += find_size(v, u);
	}
	return sz[u];
}

int find_centroid(int u, int size, int p) {
	for (int v : G[u]) {
		if (v == p || vis[v])
			continue;
		if (sz[v] * 2 > size)
			return find_centroid(v, size, u);
	}
	return u;
}

void decompose(int u, int p) {
	int c = find_centroid(u, find_size(u, -1), -1);
	vis[c] = true;
	parent[c] = p;
	for (int v : G[c]) {
		if (vis[v])
			continue;
		decompose(v, c);
	}
}

vector<int> best;
void update(int u) {
	best[u] = 0;
	int v = u;
	while (parent[v] != -1) {
		v = parent[v];
		best[v] = min(best[v], dist(u, v));
	}
}

int query(int u) {
	int ret = best[u], v = u;
	while (parent[v] != -1) {
		v = parent[v];
		ret = min(ret, best[v] + dist(u, v));
	}
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	G.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	lgN = __lg(n);
	ac.resize(n, vector<int>(lgN + 1));
	depth.resize(n);
	ac[0][0] = 0;
	DFS(0, -1);

	vis.resize(n), sz.resize(n), parent.resize(n);
	decompose(0, -1);

	best.assign(n, 0x3f3f3f3f);
	update(0);

	while (m--) {
		int t, v;
		cin >> t >> v;
		v--;
		if (t == 1)
			update(v);
		else
			cout << query(v) << '\n';
	}
}
