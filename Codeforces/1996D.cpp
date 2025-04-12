#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, x;
		cin >> n >> x;

		int ans = 0;
		for (int a = 1; a <= n - 2; a++)
			for (int b = 1; a * b <= n && a + b <= x; b++)
				ans += min((n - a * b) / (a + b), x - a - b);

		cout << ans << '\n';
	}
}
