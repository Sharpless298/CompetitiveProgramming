#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n;
vector<int> segtree;
void build(int id = 0, int L = 0, int R = n) {
	if (R - L == 1) {
		segtree[id] = INF;
		return;
	}

	int M = (L + R) / 2;
	build(id * 2 + 1, L, M);
	build(id * 2 + 2, M, R);
	segtree[id] = min(segtree[id * 2 + 1], segtree[id * 2 + 2]);
}

void update(int k, int id = 0, int L = 0, int R = n) {
	if (R - L == 1) {
		segtree[id] = (segtree[id] == INF ? k : INF);
		return;
	}

	int M = (L + R) / 2;
	(k < M) ? update(k, id * 2 + 1, L, M) : update(k, id * 2 + 2, M, R);
	segtree[id] = min(segtree[id * 2 + 1], segtree[id * 2 + 2]);
}

int query(int l, int r, int id = 0, int L = 0, int R = n) {
	if (l >= R || r <= L)
		return INF;
	if (l <= L && R <= r)
		return segtree[id];

	int M = (L + R) / 2;
	return min(query(l, r, id * 2 + 1, L, M), query(l, r, id * 2 + 2, M, R));
}

vector<vector<int>> G;
vector<int> sz, parent;
int DFS(int u, int p) {
	sz[u] = 1;
	parent[u] = p;
	for (int v : G[u]) {
		if (v == p)
			continue;
		sz[u] += DFS(v, u);
	}
	return sz[u];
}

int cnt = 0;
vector<int> id, mp, top;
void HLD(int u, int p, int t) {
	id[u] = cnt++;
	mp[id[u]] = u;
	top[u] = t;

	int h_child = -1, h_sz = -1;
	for (int v : G[u]) {
		if (v == p)
			continue;
		if (h_sz < sz[v]) {
			h_sz = sz[v];
			h_child = v;
		}
	}
	if (h_child == -1)
		return;

	HLD(h_child, u, t);
	for (int v : G[u]) {
		if (v == p || v == h_child)
			continue;
		HLD(v, u, v);
	}
}

int path(int u) {
	int ret = INF;
	while (top[u] != 0) {
		ret = min(ret, query(id[top[u]], id[u] + 1));
		u = parent[top[u]];
	}
	ret = min(ret, query(id[0], id[u] + 1));
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> n >> q;
	G.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	sz.resize(n), parent.resize(n);
	DFS(0, 0);
	id.resize(n), mp.resize(n), top.resize(n);
	HLD(0, 0, 0);
	segtree.resize(4 * n);
	build();

	while (q--) {
		int t;
		cin >> t;
		if (t == 0) {
			int i;
			cin >> i;
			i--;
			update(id[i]);
		} else {
			int v;
			cin >> v;
			v--;
			int ret = path(v);
			cout << (ret == INF ? -1 : mp[ret] + 1) << '\n';
		}
	}
}
