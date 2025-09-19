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
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		vector<int> cnt(2 * n);
		int cur = 0;
		long long ans = 1LL * n * (1 + n) / 2;
		cnt[cur]++;
		for (int i = 0; i < n; i++) {
			cur ^= a[i];
			for (int j = 0; j * j < 2 * n; j++) {
				if ((cur ^ (j * j)) < 2 * n) {
					ans -= cnt[cur ^ (j * j)];
				}
			}
			cnt[cur]++;
		}
		cout << ans << '\n';
	}
}
