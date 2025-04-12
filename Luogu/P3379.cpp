#include <iostream>
#include <vector>
using namespace std;

int lgN, n, m, s, t;
int in[500005], out[500005];
int ac[500005][32];
vector<int> G[500005];

bool ancestor(int u, int v) {
	return in[u] <= in[v] && out[u] >= out[v];
}

void DFS(int u, int f) {
	in[u] = ++t;
	for (int &v : G[u]) {
		if (v == f)
			continue;

		ac[v][0] = u;
		for (int i = 1; i <= lgN; i++)
			ac[v][i] = ac[ac[v][i - 1]][i - 1];
		DFS(v, u);
	}
	out[u] = t;
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

	cin >> n >> m >> s;
	for (int i = 0, x, y; i < n - 1; i++) {
		cin >> x >> y;

		G[x].push_back(y);
		G[y].push_back(x);
	}

	lgN = __lg(n);
	for (int i = 0; i <= lgN; i++)
		ac[s][i] = s;
	DFS(s, -1);

	while (m--) {
		int a, b;

		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}
}
