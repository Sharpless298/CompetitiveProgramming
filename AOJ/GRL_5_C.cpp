#include <iostream>
#include <vector>
using namespace std;

int lgN, t;
vector<int> in, out;
vector<vector<int>> ac, G;

void DFS(int u) {
	in[u] = ++t;
	for (int &v : G[u]) {
		ac[v][0] = u;
		for (int i = 1; i <= lgN; i++)
			ac[v][i] = ac[ac[v][i - 1]][i - 1];
		DFS(v);
	}
	out[u] = ++t;
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

	int n;
	cin >> n;
	G.resize(n);
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for (int j = 0, u; j < k; j++) {
			cin >> u;
			G[i].push_back(u);
		}
	}
	lgN = __lg(n);
	in.resize(n), out.resize(n);
	ac.resize(n, vector<int>(lgN + 1));
	ac[0][0] = 0;
	DFS(0);

	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;

		cout << LCA(u, v) << '\n';
	}
}
