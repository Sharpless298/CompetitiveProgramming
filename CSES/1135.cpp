#include <iostream>
#include <vector>
using namespace std;

int lgN, t;
vector<int> in, out, d;
vector<vector<int>> G, ac;

void DFS(int u, int f) {
	in[u] = t++;
	for (int v : G[u]) {
		if (v == f)
			continue;

		d[v] = d[u] + 1;
		ac[v][0] = u;
		for (int i = 1; i <= lgN; i++)
			ac[v][i] = ac[ac[v][i - 1]][i - 1];
		DFS(v, u);
	}
	out[u] = t;
}

bool ancestor(int u, int v) {
	return in[u] <= in[v] && out[u] >= out[v];
}

int LCA(int u, int v) {
	if (ancestor(u, v))
		return u;

	for (int i = lgN; i >= 0; i--)
		if (!ancestor(ac[u][i], v))
			u = ac[u][i];

	return ac[u][0];
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;
	G.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	lgN = __lg(n);
	in.resize(n);
	out.resize(n);
	ac.resize(n, vector<int>(lgN + 1));
	ac[0][0] = 0;
	d.resize(n);
	DFS(0, -1);
	while (q--) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		cout << d[a] + d[b] - 2 * d[LCA(a, b)] << '\n';
	}
}
