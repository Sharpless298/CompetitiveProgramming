#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long MOD = 1e9 + 7;
const long long P = rng() % MOD + 26;

int f(string &s) {
	int n = (int)s.size();

	vector<long long> power(n + 1);
	power[0] = 1;
	for (int i = 0; i < n; i++) {
		power[i + 1] = power[i] * P % MOD;
	}

	vector<long long> pref(n + 1);
	pref[0] = 0;
	for (int i = 0; i < n; i++) {
		pref[i + 1] = (pref[i] * P + s[i] - 'a') % MOD;
	}
	string t(s.rbegin(), s.rend());
	vector<long long> suf(n + 1);
	suf[0] = 0;
	for (int i = 0; i < n; i++) {
		suf[i + 1] = (suf[i] * P + t[i] - 'a') % MOD;
	}

	for (int i = n; i >= 0; i--) {
		if (pref[i] == (((suf[n] - suf[n - i] * power[i] % MOD) % MOD + MOD) % MOD)) {
			return i;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = (int)s.size();

		string ans;
		int c = 0;
		while (c < (n / 2) && s[c] == s[n - c - 1]) {
			c++;
		}
		ans += s.substr(0, c);
		ans += s.substr(n - c);

		s = s.substr(c, n - 2 * c);
		string rs(s.rbegin(), s.rend());
		int len_s = f(s), len_rs = f(rs);
		if (len_s > len_rs) {
			ans.insert(c, s.substr(0, len_s));
		} else {
			ans.insert(c, rs.substr(0, len_rs));
		}
		cout << ans << '\n';
	}
}
