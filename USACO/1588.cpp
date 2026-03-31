#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const int N = 2e5 + 5;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<long long> dp(N), pref(N + 1);
	dp[0] = 1;
	pref[1] = dp[0];
	for (int i = 1; i < N; i++) {
		dp[i] = (2 + pref[i]) % MOD;
		pref[i + 1] = (pref[i] + dp[i]) % MOD;
	}

	int T;
	cin >> T;
	while (T--) {
		string x;
		cin >> x;
		reverse(x.begin(), x.end());

		int n = (int)x.size();
		auto f = [&](string &s) {
			bool ret = false;
			for (int i = 0; i < n; i++) {
				s[i] -= '0';
				if (s[i] != 0 && s[i] != 1) {
					s[i] %= 2;
					ret = true;
				}
			}
			return ret;
		};

		long long ans = (f(x) ? 1 : 0);
		for (int i = 0; i < n; i++) {
			if (x[i]) {
				ans = (ans + dp[i]) % MOD;
			}
		}
		cout << ans << '\n';
	}
}
