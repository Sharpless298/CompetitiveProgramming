#include <iostream>
#include <vector>
using namespace std;

int N, Q, S, T, K, lgN, t, lca, d1, d2;
int in[100005], out[100005], d[100005], ac[20][100005];
vector<int> G[100005];

bool ancestor(int u, int v) {
	if (in[u] <= in[v] && out[u] >= out[v])
		return true;
	return false;
}

void DFS(int u, int f) {
	d[u] = d[f] + 1;
	in[u] = ++t;
	for (int v : G[u])
		if (v != f)
			ac[0][v] = u, DFS(v, u);
	out[u] = t;
}

int LCA(int u, int v) {
	if (ancestor(u, v))
		return u;

	for (int i = lgN; i >= 0; i--)
		if (!ancestor(ac[i][u], v))
			u = ac[i][u];
	return ac[0][u];
}

int dis(int u, int v) {
	return d[u] + d[v] - 2 * d[LCA(u, v)];
}

int f(int u, int k) {
	if (!k)
		return u;
	int lgk = __lg(k);

	for (int i = 0; i <= lgk; i++, k >>= 1)
		if (k & 1)
			u = ac[i][u];
	return u;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> Q;
	for (int i = 0, u, v; i < N - 1; i++) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	lgN = __lg(N);
	DFS(1, 0);
	ac[0][1] = 1;
	for (int i = 1; i <= lgN; i++)
		for (int j = 1; j <= N; j++)
			ac[i][j] = ac[i - 1][ac[i - 1][j]];

	while (Q--) {
		cin >> S >> T >> K;

		lca = LCA(S, T);
		d1 = dis(S, T), d2 = dis(S, lca);
		if (K > d1)
			cout << -1 << '\n';
		else if (K >= d2)
			cout << f(T, d1 - K) << '\n';
		else
			cout << f(S, K) << '\n';
	}
}
