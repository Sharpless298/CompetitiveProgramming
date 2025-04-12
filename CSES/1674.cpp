#include <bits/stdc++.h>
using namespace std;

vector<int> sz;
vector<vector<int>> G;
int DFS(int u) {
	sz[u] = 1;
	for (int v : G[u])
		sz[u] += DFS(v);
	return sz[u];
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	G.resize(n);
	for (int i = 1; i < n; i++) {
		int u;
		cin >> u;
		u--;
		G[u].push_back(i);
	}
	sz.resize(n);
	DFS(0);
	for (int i : sz)
		cout << i - 1 << ' ';
	cout << '\n';
}
