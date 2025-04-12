#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int x, n, m;
		cin >> x >> n >> m;

		auto f = [](int xx, int nn) {
			while (nn--) {
				if (xx == 0)
					return xx;
				xx = (xx >> 1);
			}
			return xx;
		};
		auto g = [](int xx, int mm) {
			while (mm--) {
				if (xx <= 1)
					return xx;
				xx = ((xx + 1) >> 1);
			}
			return xx;
		};

		cout << f(g(x, m), n) << ' ' << g(f(x, n), m) << '\n';
	}
}
