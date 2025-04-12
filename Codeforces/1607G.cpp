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
		vector<int> a(n), b(n);
		long long bal = 0, max_a = 0, max_b = 0;
		long long tot = 1LL * n * m;
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i];
			bal += a[i] - b[i];
			max_a += min(m, a[i]);
			max_b += min(m, b[i]);
		}
		long long max_delta = 2 * max_a - tot, min_delta = tot - 2 * max_b;
		long long min_a = tot - max_b;

		long long eat_a;
		if (bal < 0) {
			eat_a = min_a;
			if (bal - min_delta >= 0)
				eat_a = min(max_a, (tot + bal + 1) / 2);
		} else {
			eat_a = max_a;
			if (bal - max_delta <= 0)
				eat_a = min(max_a, (tot + bal + 1) / 2);
		}

		cout << abs(bal - 2 * eat_a + tot) << '\n';
		long long r = eat_a - min_a;
		for (int i = 0; i < n; i++) {
			long long t = (b[i] < m ? m - b[i] : 0);
			long long add = min({r, m - t, a[i] - t});
			t += add;
			r -= add;
			cout << t << ' ' << m - t << '\n';
		}
	}
}
