#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long h, w, k;
	cin >> h >> w >> k;

	array<array<long long, 2>, 2> dp = {};
	dp[0][0] = 1;
	while (k--) {
		array<array<long long, 2>, 2> ndp = {};
		ndp[0][0] = (dp[0][1] + dp[1][0]) % MOD;
		ndp[0][1] = ((w - 1) * dp[0][0] % MOD + (w - 2) * dp[0][1] % MOD + dp[1][1]) % MOD;
		ndp[1][0] = ((h - 1) * dp[0][0] % MOD + (h - 2) * dp[1][0] % MOD + dp[1][1]) % MOD;
		ndp[1][1] = ((h - 1) * dp[0][1] % MOD + (w - 1) * dp[1][0] % MOD + (h - 2 + w - 2) * dp[1][1]) % MOD;
		dp = ndp;
	}
	function<long long(long long)> inv = [&](long long x) {
		return x <= 1LL ? x : (MOD - MOD / x) * inv(MOD % x) % MOD;
	};
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	long long a = (x1 == x2 ? 1 : h - 1), b = (y1 == y2 ? 1 : w - 1);
	cout << dp[x1 != x2][y1 != y2] * inv(a * b % MOD) % MOD << '\n';
}
