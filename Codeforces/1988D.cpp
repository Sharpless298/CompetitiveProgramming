#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int64_t> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<vector<int>> G(n);
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}

		vector dp(n, vector<int64_t>(20));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 20; j++) {
				dp[i][j] = a[i] * (j + 1);
			}
		}
		auto DFS = [&](auto &&self, int u, int p) -> void {
			for (int v : G[u]) {
				if (v != p) {
					self(self, v, u);
					for (int i = 0; i < 20; i++) {
						int64_t mn = 1LL << 60;
						for (int j = 0; j < 20; j++) {
							if (j != i) {
								mn = min(mn, dp[v][j]);
							}
						}
						dp[u][i] += mn;
					}
				}
			}
		};

		DFS(DFS, 0, -1);
		cout << *min_element(dp[0].begin(), dp[0].end()) << '\n';
	}
}
