#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		long long l, r;
		int i, k;
		cin >> l >> r >> i >> k;

		function<long long(long long)> f = [](long long x) -> long long {
			long long y = (x - 1) % 4;
			if (x == 0) {
				return 0;
			} else if (y == 0) {
				return 1;
			} else if (y == 1) {
				return x / 4 * 4 + 3;
			} else if (y == 2) {
				return 0;
			} else {
				return x;
			}
		};
		long long ans = f(l - 1) ^ f(r);
		long long m = 1LL << i;
		if (l - k - 1 < 0) {
			l = k;
		} else {
			l = ((l - k - 1) / m + 1) * m + k;
		}
		if (l <= r) {
			long long c = (r - l) / m + 1;
			for (int j = 0; j < i; j++) {
				ans ^= ((l >> j & 1) & (c & 1)) << j;
			}
			if ((l >> i) - 1 >= 0) {
				ans ^= (f((l >> i) - 1) << i);
			}
			ans ^= (f((l >> i) + c - 1) << i);
		}
		cout << ans << '\n';
	}
}
