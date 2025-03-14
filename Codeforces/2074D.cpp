#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;

		vector<long long> x(n), r(n);
		for (long long &i : x) cin >> i;
		for (long long &i : r) cin >> i;

		map<long long, long long> mp;
		for (int i = 0; i < n; i++) {
			for (long long p = x[i] - r[i]; p <= x[i] + r[i]; p++) {
				long long k = r[i] * r[i] - (p - x[i]) * (p - x[i]);

				long long low = 0, high = 200001;
				while (low < high) {
					long long mid = (low + high) / 2;

					if (mid * mid <= k)
						low = mid + 1;
					else
						high = mid;
				}
				mp[p] = max(mp[p], low - 1);
			}
		}

		long long ans = 0;
		for (pair<long long, long long> p : mp) ans += 1 + p.second * 2;
		cout << ans << '\n';
	}
}
