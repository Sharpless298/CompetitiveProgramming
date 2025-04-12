#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		long long k, l1, r1, l2, r2;
		cin >> k >> l1 >> r1 >> l2 >> r2;

		vector<long long> pow;
		long long t = 1;
		while (t <= r2 / l1) {
			pow.push_back(t);
			t *= k;
		}

		long long ans = 0;
		for (long long p : pow)
			ans += max(0LL, min(r2 / p, r1) - max((l2 - 1) / p + 1, l1) + 1);

		cout << ans << '\n';
	}
}
