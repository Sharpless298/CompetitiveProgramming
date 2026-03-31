#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<vector<int>> G(n);
		for (int i = 1; i < n; i++) {
			int p;
			cin >> p;
			p--;
			G[p].push_back(i);
			G[i].push_back(p);
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
		DFS(0, 0);

		int len = 1 << 30;
		vector<int> cnt(n);
		for (int i = 0; i < n; i++) {
			if (G[i].size() == 1 && i != 0) {
				len = min(len, d[i] + 1);
			}
			cnt[d[i]]++;
		}

		int c = n, ans = len;
		cnt.resize(len);
		for (int i = 0; i < len; i++) {
			c -= cnt[i];
		}

		if (k > n - k) {
			k = n - k;
		}
		bitset<100001> bs;
		bs[0] = 1;
		for (int i = 0; i < len; i++) {
			bs |= bs << cnt[i];
		}
		int ok = 0;
		for (int i = 0; i <= min(k, c); i++) {
			ok |= bs[k - i];
		}
		cout << ans - 1 + ok << '\n';
	}
}
