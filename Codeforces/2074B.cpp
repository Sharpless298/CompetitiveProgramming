#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int ans = 0;
		for (int i = 0, x; i < n; i++)
			cin >> x, ans += x;

		ans -= max(0, n - 1);
		cout << ans << '\n';
	}
}
