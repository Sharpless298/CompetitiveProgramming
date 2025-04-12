#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		long long m;
		cin >> n >> m;
		vector<long long> a(n);
		map<long long, long long> mp;
		for (long long &i : a)
			cin >> i;
		for (int i = 0; i < n; i++) {
			long long x;
			cin >> x;
			mp[a[i]] += x;
		}

		long long ans = 0;
		for (auto &[k, c0] : mp) {
			auto it = mp.find(k + 1);
			auto c1 = (it != mp.end() ? it->second : 0);

			auto k1 = min(c0, m / k);
			auto k2 = min(c1, (m - k * k1) / (k + 1));
			auto cnt = min({k1, c1 - k2, (m - k * k1) % (k + 1)});
			ans = max(ans, k * k1 + (k + 1) * k2 + cnt);
		}

		cout << ans << '\n';
	}
}
