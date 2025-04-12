#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	bool f;
	int n, D, ans = 0;

	cin >> n >> D;

	for (int i = 0, x, y; i < n; i++) {
		cin >> x;

		if (i == 0) {
			f = true;
			y = x;
			continue;
		}
		if (f && x >= y + D) {
			f = false;
			ans += x - y;
			y = x;
		} else if (!f && x <= y - D) {
			f = true;
			y = x;
		} else
			continue;
	}

	cout << ans << '\n';
}
