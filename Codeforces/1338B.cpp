#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<vector<int>> G(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	vector<int> d(n);
	function<void(int, int)> DFS = [&](int u, int p) {
		for (int v : G[u]) {
			if (v != p) {
				d[v] = d[u] + 1;
				DFS(v, u);
			}
		}
	};
	DFS(0, -1);
	int parity = -1, mn = 1;
	for (int i = 0; i < n; i++) {
		if (G[i].size() == 1) {
			if (parity == -1) {
				parity = d[i] % 2;
			} else {
				if ((parity - d[i]) % 2) {
					mn = 3;
					break;
				}
			}
		}
	}

	int mx = n - 1;
	vector<bool> f(n);
	for (int i = 0; i < n; i++) {
		if (G[i].size() == 1) {
			if (!f[G[i][0]]) {
				f[G[i][0]] = true;
			} else {
				mx--;
			}
		}
	}
	cout << mn << ' ' << mx << '\n';
}
