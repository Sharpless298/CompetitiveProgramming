#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		long long n;
		cin >> n;

		int cnt = 0, ans = 0x3f3f3f3f;
		long long t = n;

		while (t % 10 != 0)
			t /= 10, cnt++;
		while (t > 50 && t % 100 / 10 != 5 && t % 100 / 10 != 0)
			t = t / 100 * 10, cnt++;
		if (t >= 50)
			ans = cnt;

		cnt = 0;
		while (n > 0 && n % 10 != 5)
			n /= 10, cnt++;
		while (n > 25 && n % 100 / 10 != 2 && n % 100 / 10 != 7)
			n = n / 100 * 10 + 5, cnt++;
		if (n >= 25)
			ans = min(ans, cnt);

		cout << ans << '\n';
	}
}
