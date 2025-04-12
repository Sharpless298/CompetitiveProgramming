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
		vector<int> a(n), b(n);
		for (int &i : a)
			cin >> i;
		for (int &i : b)
			cin >> i;

		int l = 0, r = 1e9 + 1;
		while (l < r) {
			int m = (l + r) / 2;

			int sum = 0;
			for (int i = 0; i < n; i++) {
				if (sum > 1e9)
					break;
				if (a[i] < m)
					continue;
				;
				if (a[i] >= m)
					sum += (a[i] - m) / b[i] + 1;
			}

			if (sum >= k)
				l = m + 1;
			else
				r = m;
		}

		int cnt = 0;
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] < l)
				continue;
			int m = (a[i] - l) / b[i] + 1;
			ans += 1LL * a[i] * m - 1LL * m * (m - 1) / 2 * b[i];
			cnt += m;
		}
		ans += 1LL * max(l - 1, 0) * (k - cnt);

		cout << ans << '\n';
	}
}
