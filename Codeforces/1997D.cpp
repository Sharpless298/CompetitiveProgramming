#include <bits/stdc++.h>
using namespace std;

vector<int> a;
vector<vector<int>> G;
int f(int u) {
	if (G[u].size() == 0)
		return a[u];

	int mn = 0x3f3f3f3f;
	for (int v : G[u])
		mn = min(mn, f(v));

	return mn >= a[u] ? (mn + a[u]) / 2 : mn;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		a.resize(n);
		for (int &i : a)
			cin >> i;

		G.clear();
		G.resize(n);
		for (int i = 1; i < n; i++) {
			int u;
			cin >> u, u--;

			G[u].push_back(i);
		}

		int mn = 0x3f3f3f3f;
		for (int u : G[0])
			mn = min(mn, f(u));

		cout << mn + a[0] << '\n';
	}
}
