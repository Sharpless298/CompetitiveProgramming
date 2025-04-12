#include <iostream>
using namespace std;

typedef long long int lli;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, x, y, z;
	lli k, t, ans;

	cin >> T;
	while (T--) {
		ans = 0;

		cin >> x >> y >> z >> k;

		for (int i = 1; i <= x; i++) {
			for (int j = 1; j <= y; j++) {
				t = k / i / j;
				if (i * j * t != k || t > z)
					continue;

				ans = max(ans, 1LL * (x - i + 1) * (y - j + 1) * (z - t + 1));
			}
		}

		cout << ans << '\n';
	}
}
