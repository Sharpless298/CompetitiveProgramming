#include <iostream>
#include <vector>
using namespace std;

int t, n;
vector<int> in, euler_tour;
vector<vector<int>> G;

void DFS(int u, int f) {
	in[u] = t;
	euler_tour[t++] = u;
	for (int v : G[u]) {
		if (v == f)
			continue;
		DFS(v, u);
		euler_tour[t++] = u;
	}
}

vector<int> segtree;

int f(int u, int v) {
	if (u == -1)
		return v;
	if (v == -1)
		return u;
	return in[u] < in[v] ? u : v;
}

void build(int id = 0, int L = 0, int R = n) {
	if (R - L == 1) {
		segtree[id] = euler_tour[L];
		return;
	}

	int M = (L + R) / 2;
	build(id * 2 + 1, L, M);
	build(id * 2 + 2, M, R);
	segtree[id] = f(segtree[id * 2 + 1], segtree[id * 2 + 2]);
}

int query(int l, int r, int id = 0, int L = 0, int R = n) {
	if (l >= R || r <= L)
		return -1;
	if (l <= L && R <= r)
		return segtree[id];

	int M = (L + R) / 2;
	return f(query(l, r, id * 2 + 1, L, M), query(l, r, id * 2 + 2, M, R));
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> n >> q;
	in.resize(n);
	G.resize(n);
	for (int i = 1; i < n; i++) {
		int u;
		cin >> u;
		u--;
		G[i].push_back(u);
		G[u].push_back(i);
	}
	n = n * 2 - 1;

	euler_tour.resize(n);
	DFS(0, -1);

	segtree.resize(4 * n);
	build();

	while (q--) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		if (in[a] > in[b])
			swap(a, b);
		cout << query(in[a], in[b] + 1) + 1 << '\n';
	}
}
