#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int &i : a)
			cin >> i, i--;
		vector<vector<int>> G(n);
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}

		string ans(n, '0');
		for (int u = 0; u < n; u++) {
			map<int, int> cnt;
			for (int v : G[u])
				if (++cnt[a[v]] >= 2)
					ans[a[v]] = '1';
			if (++cnt[a[u]] >= 2)
				ans[a[u]] = '1';
		}
		cout << ans << '\n';
	}
}
