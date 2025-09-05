#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 998244353;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		vector<int> c(26);
		for (int i = 0; i < 26; i++) {
			cin >> c[i];
		}

		int sum = accumulate(c.begin(), c.end(), 0);
		vector<int> dp(sum + 1);
		dp[0] = 1;
		for (int i = 0; i < 26; i++) {
			if (c[i] == 0) {
				continue;
			}

			for (int j = sum; j >= 0; j--) {
				if (j + c[i] <= sum) {
					dp[j + c[i]] = (dp[j + c[i]] + dp[j]) % MOD;
				}
			}
		}

		auto fact = [](int n) {
			int ret = 1;
			for (int i = 1; i <= n; i++) {
				ret = ret * i % MOD;
			}
			return ret;
		};
		auto bpow = [](int a, int b) {
			int ret = 1;
			while (b) {
				if (b & 1) {
					ret = ret * a % MOD;
				}
				a = a * a % MOD, b >>= 1;
			}
			return ret;
		};

		int ans = dp[sum / 2] * fact(sum / 2) % MOD * fact((sum + 1) / 2) % MOD;
		for (int i = 0; i < 26; i++) {
			ans = (ans * bpow(fact(c[i]), MOD - 2)) % MOD;
		}
		cout << ans << '\n';
	}
}
