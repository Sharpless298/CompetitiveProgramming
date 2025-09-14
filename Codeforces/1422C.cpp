#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	reverse(s.begin(), s.end());

	int n = (int)s.size();
	vector<long long> pref(n + 1);
	pref[0] = 0;
	for (int i = 0; i < n; i++) {
		pref[i + 1] = pref[i] + s[i] - '0';
	}

	vector<long long> c(n);
	for (int i = 0; i < n; i++) {
		c[i] = 1LL * (n - i) * (n - i - 1) / 2 * (s[i] - '0') % MOD;
		c[i] = (c[i] + 1LL * (i + 1) * (pref[n] - pref[i + 1])) % MOD;
	}

	long long ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		ans = ans * 10 % MOD;
		ans = (ans + c[i]) % MOD;
	}

	cout << ans << '\n';
}
