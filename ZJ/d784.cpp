#include <iostream>
using namespace std;

int T, n, ans, ary[105], dp[105];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> ary[i];

		ans = dp[0] = ary[0];
		for (int i = 1; i < n; i++) {
			dp[i] = max(dp[i - 1] + ary[i], ary[i]);
			ans = max(ans, dp[i]);
		}

		cout << ans << '\n';
	}
}
