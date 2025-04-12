#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> sz;
vector<vector<int>> G;
int DFS(int u, int p) {
	sz[u] = 1;
	for (int v : G[u]) {
		if (v == p)
			continue;
		sz[u] += DFS(v, u);
	}
	return sz[u];
}

int find_centroid(int u, int p) {
	for (int v : G[u]) {
		if (v == p)
			continue;
		if (sz[v] * 2 > n)
			return find_centroid(v, u);
	}
	return u;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	sz.resize(n), G.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	DFS(0, -1);
	cout << find_centroid(0, -1) + 1 << '\n';
}
