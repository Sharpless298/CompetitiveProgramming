#include <iostream>
using namespace std;

int T, x, y, t, cnt, ans;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cnt = 0;

		cin >> x >> y;

		t = x ^ y;
		t = t & (-t);
		while (t)
			t >>= 1, cnt++;

		ans = 1;
		for (int i = 0; i < cnt - 1; i++)
			ans *= 2;

		cout << ans << '\n';
	}
}
