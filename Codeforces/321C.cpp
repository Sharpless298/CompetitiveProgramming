#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<bool> vis;
vector<int> sz;
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

int root = -1;
vector<vector<int>> centroid_tree;
void decompose(int u, int p) {
	int c = find_centroid(u, find_size(u, -1), -1);

	if (root == -1)
		root = c;
	vis[c] = true;
	if (p != -1)
		centroid_tree[p].push_back(c);
	for (int v : G[c]) {
		if (vis[v])
			continue;
		decompose(v, c);
	}
}

vector<char> ans;
void DFS(int u, int p) {
	for (int v : centroid_tree[u]) {
		if (v == p)
			continue;
		ans[v] = ans[u] + 1;
		DFS(v, u);
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	G.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	sz.resize(n), vis.resize(n), centroid_tree.resize(n);
	decompose(0, -1);

	ans.resize(n);
	ans[root] = 'A';
	DFS(root, -1);
	for (int i = 0; i < n; i++)
		cout << ans[i] << " \n"[i + 1 == n];
}
