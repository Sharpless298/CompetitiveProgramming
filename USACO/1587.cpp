#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		bool neg = (k < 0);
		k = abs(k);
		vector<vector<long long>> a(k);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (neg) {
				x *= -1;
			}
			int c = (x % k + k) % k;
			a[c].push_back(x);
		}
		k = abs(k);

		long long ans = 0;
		for (int i = 0; i < k; i++) {
			sort(a[i].begin(), a[i].end());
			for (int j = 1; j < (int)a[i].size(); j++) {
				long long c = max(0LL, 1LL * (a[i][j - 1] - a[i][j]) / k + 1);
				ans += c;
				a[i][j] += c * k;
			}
		}
		cout << ans << '\n';
	}
}
