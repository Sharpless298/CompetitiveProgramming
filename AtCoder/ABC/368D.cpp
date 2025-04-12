#include <iostream>
#include <vector>
using namespace std;

vector<int> f;
vector<vector<int>> G;

void DFS(int u, int pre) {
	for (int &v : G[u]) {
		if (v == pre)
			continue;
		DFS(v, u);
		if (f[v])
			f[u] = 1;
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	G.resize(n);
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v;
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	int v;
	f.resize(n);
	for (int i = 0; i < k; i++) {
		cin >> v;
		v--;
		f[v] = 1;
	}

	DFS(v, -1);

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += f[i];

	cout << ans << '\n';
}
