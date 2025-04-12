#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int n = (int)s.size();
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			a[i] = (s[i] == '0' ? -1 : 1);

		vector<int> pref(n + 1);
		for (int i = 0; i < n; i++)
			pref[i + 1] = pref[i] + a[i];

		long long ans = 0;
		map<int, long long> mp;
		for (int i = 0; i <= n; i++) {
			ans = (ans + (n - i + 1) * mp[pref[i]]) % MOD;
			mp[pref[i]] = (mp[pref[i]] + i + 1) % MOD;
		}
		cout << ans << '\n';
	}
}
