#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a, b;
		cin >> a >> b;
		a--, b--;
		vector<vector<int>> G(n);
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}

		int root = -1, ans = 0;
		queue<int> q;
		if (a == b) {
			root = a;
		} else {
			vector<int> stk;
			function<bool(int, int)> DFS = [&](int u, int p) {
				stk.push_back(u);
				if (u == b) {
					return true;
				}
				for (int v : G[u]) {
					if (v != p) {
						if (DFS(v, u)) {
							return true;
						}
					}
				}
				stk.pop_back();
				return false;
			};

			DFS(a, -1);
			root = stk[(stk.size() - 1) / 2];
			ans += (int)stk.size() / 2;
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
		DFS(root, -1);
		ans += 2 * (n - 1) - *max_element(d.begin(), d.end());
		cout << ans << '\n';
	}
}
