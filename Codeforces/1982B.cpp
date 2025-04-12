#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, x, y, k;

	cin >> T;
	while (T--) {
		cin >> x >> y >> k;

		while (x > 1 && k) {
			x++, k--;

			int temp = min(k, (y - x % y) % y);
			x += temp;
			k -= temp;
			while (x % y == 0)
				x /= y;
		}

		if (x == 1)
			cout << 1 + k % (y - 1) << '\n';
		else
			cout << x << '\n';
	}
}
