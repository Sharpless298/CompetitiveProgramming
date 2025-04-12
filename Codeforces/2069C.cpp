#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> dp(4, 0);
		dp[0] = 1;
		while (n--) {
			int x;
			cin >> x;
			if (x == 2)
				dp[x] = dp[x] * 2 % MOD;
			dp[x] = (dp[x] + dp[x - 1]) % MOD;
		}
		cout << dp[3] << '\n';
	}
}
