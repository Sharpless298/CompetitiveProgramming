#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		long long h, d;
		cin >> h >> d;

		if (h == 1) {
			cout << 2 * d << '\n';
			continue;
		}

		auto f = [](long long x) {
			return (1 + x) * x / 2;
		};
		long long low = d - 1, high = 2e9;
		while (high - low > 1) {
			long long mid = (low + high) / 2;

			long long rest = mid - d;
			long long k = d / (rest + 1);
			long long r = d % (rest + 1);
			if (h + rest > f(k + 1) * r + f(k) * (rest + 1 - r)) {
				high = mid;
			} else {
				low = mid;
			}
		}
		cout << high << '\n';
	}
}
