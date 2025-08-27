#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) {
		int n, m, k, q;
		cin >> n >> m >> k >> q;
		vector<pair<int, int>> a(q);
		for (int i = 0; i < q; i++) {
			cin >> a[i].first >> a[i].second;
		}

		set<int> X, Y;
		int ans = 1;
		for (int i = q - 1; i >= 0; i--) {
			bool f = false;
			if (!X.count(a[i].first)) {
				X.insert(a[i].first);
				f = true;
			}
			if (!Y.count(a[i].second)) {
				Y.insert(a[i].second);
				f = true;
			}
			if (f) {
				ans = 1LL * ans * k % MOD;
			}
			
			if ((int)X.size() == n || (int)Y.size() == m) {
				break;
			}
		}
		cout << ans << '\n';
	}
}
