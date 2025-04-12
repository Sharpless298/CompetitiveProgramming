#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	function<long long(long long)> inv = [&](long long x) {
		return (x <= 1LL ? x : (MOD - MOD / x) * inv(MOD % x) % MOD);
	};
	long long inv2 = inv(2LL);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		string s;
		cin >> s;

		long long dp = 0;
		for (int i = n - 1; i > 0; i--)
			dp = (dp + (s[i] == '1')) * inv2 % MOD;

		cout << (dp + n - 1) % MOD << '\n';
	}
}
