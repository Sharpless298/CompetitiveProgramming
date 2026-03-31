#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc = 1;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		vector<pair<int, int>> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i].first;
		}
		for (int i = 0; i < n; i++) {
			cin >> a[i].second;
		}
		sort(a.begin(), a.end());

		int l = -1, r = (int)1e9 + 10000;
		while (r - l > 1) {
			int m = (l + r) / 2;

			int cnt = 0, tmp = k;
			for (int i = n - 1; i >= 0; i--) {
				if (a[i].first >= m) {
					cnt++;
				} else if (a[i].second && tmp >= m - a[i].first) {
					tmp -= m - a[i].first;
					cnt++;
				}
			}

			if (cnt >= (n + 1) / 2 + 1) {
				l = m;
			} else {
				r = m;
			}
		}
		int ans = -1;
		for (int i = n - 1; i >= 0; i--) {
			if (a[i].second) {
				auto v = a;
				v[i].first += k;
				sort(v.begin(), v.end());
				ans = v.back().first + v[(n - 2) / 2].first;
				break;
			}
		}
		for (int i = n - 1, tmp = k; i >= 0; i--) {
			if (a[i].first < l && a[i].second) {
				if (tmp >= l - a[i].first) {
					a[i].first = l;
					tmp -= l - a[i].first;
				}
			}
		}
		sort(a.begin(), a.end());
		ans = max(ans, a.back().first + a[(n - 2) / 2].first);
		cout << ans << '\n';
	}
}
