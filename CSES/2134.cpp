#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
inline void readint(T &x) {
	char c;
	x = 0;
	int f = 1;
	c = (char)getchar();
	while (c > 57 || c < 48) {
		if (c == 45) {
			f = -1;
		}
		c = (char)getchar();
	}
	while (c <= 57 && c >= 48) {
		x = (x << 3) + (x << 1) + c - 48;
		c = (char)getchar();
	}
	x *= f;
}

const int N = 2e5;

vector<int> a(N), segtree(4 * N);
vector<vector<int>> G(N);

void update(int s, int x, int id = 0, int L = 0, int R = N) {
	if (R - L == 1) {
		segtree[id] = x;
		return;
	}

	int M = (L + R) / 2;
	s < M ? update(s, x, id * 2 + 1, L, M) : update(s, x, id * 2 + 2, M, R);
	segtree[id] = max(segtree[id * 2 + 1], segtree[id * 2 + 2]);
}

int query(int l, int r, int id = 0, int L = 0, int R = N) {
	if (l >= R || r <= L)
		return 0;
	if (l <= L && R <= r)
		return segtree[id];

	int M = (L + R) / 2;
	return max(query(l, r, id * 2 + 1, L, M), query(l, r, id * 2 + 2, M, R));
}

vector<int> sz(N), parent(N), depth(N);
int DFS(int u, int p) {
	sz[u] = 1;
	parent[u] = p;
	for (int v : G[u]) {
		if (v == p)
			continue;
		depth[v] = depth[u] + 1;
		sz[u] += DFS(v, u);
	}
	return sz[u];
}

int cnt = 0;
vector<int> id(N), top(N);
void HLD(int u, int p, int t) {
	id[u] = cnt++;
	top[u] = t;
	update(id[u], a[u]);

	int h_child = -1, h_sz = -1;
	for (int v : G[u]) {
		if (v == p)
			continue;
		if (sz[v] > h_sz) {
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

int path(int u, int v) {
	int ret = 0;
	while (top[u] != top[v]) {
		if (depth[top[u]] < depth[top[v]])
			swap(u, v);
		ret = max(ret, query(id[top[u]], id[u] + 1));
		u = parent[top[u]];
	}
	if (depth[u] > depth[v])
		swap(u, v);
	ret = max(ret, query(id[u], id[v] + 1));
	return ret;
}

signed main() {
	int n, q;
	readint(n), readint(q);
	for (int i = 0; i < n; i++)
		readint(a[i]);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		readint(u), readint(v);
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	DFS(0, 0);
	HLD(0, 0, 0);

	while (q--) {
		int t;
		readint(t);
		if (t == 1) {
			int s, x;
			readint(s), readint(x);
			s--;
			update(id[s], x);
		} else {
			int u, v;
			readint(u), readint(v);
			u--, v--;
			cout << path(u, v) << ' ';
		}
	}
	cout << '\n';
}
