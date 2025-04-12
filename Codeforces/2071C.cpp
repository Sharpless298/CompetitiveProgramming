#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, st, en;
		cin >> n >> st >> en;
		st--, en--;
		vector<vector<int>> G(n);
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}

		vector<int> sp;
		sp.push_back(-1);
		sp.push_back(st);
		function<void(int, int)> DFS = [&](int u, int p) {
			for (int v : G[u]) {
				if (v == p)
					continue;

				sp.push_back(v);
				DFS(v, u);
				if (sp.back() == en)
					return;
				sp.pop_back();
			}
		};
		DFS(st, -1);
		sp.push_back(-1);

		vector<int> ans;
		function<void(int, int, int)> DFS2 = [&](int u, int p, int t) {
			for (int v : G[u]) {
				if (v == p || v == sp[t - 1] || v == sp[t + 1])
					continue;

				DFS2(v, u, t);
			}
			ans.push_back(u);
		};
		for (int i = 1; i < (int)sp.size() - 1; i++)
			DFS2(sp[i], -1, i);

		for (int i : ans)
			cout << i + 1 << ' ';
		cout << '\n';
	}
}
