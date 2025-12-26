#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> fact(200001);
	fact[0] = 1;
	for (int i = 1; i <= 200000; i++) {
		fact[i] = (1LL * fact[i - 1] * i) % MOD;
	}

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> G(n);
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}

		int ans = 2, c = 0;
		if (m >= n) {
			ans = 0;
		}
		for (int u = 0; u < n; u++) {
			if (G[u].size() > 1) {
				int cnt = 0;
				for (int v : G[u]) {
					cnt += (G[v].size() == 1);
				}
				if (cnt >= (int)G[u].size() - 2) {
					ans = 1LL * ans * fact[cnt] % MOD;
				} else {
					ans = 0;
				}
			} else {
				c++;
			}
		}
		c = (c < n - 1 ? 2 : 1);
		ans = 1LL * ans * c % MOD;
		cout << ans << '\n';
	}
}
