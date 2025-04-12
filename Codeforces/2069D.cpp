#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int n = (int)s.size();
		int t = 0;
		while (t < n / 2 && s[t] == s[n - t - 1])
			t++;
		n -= t * 2;
		s = s.substr(t, n);

		int ans = n;
		for (int j = 0; j < 2; j++) {
			int l = 0, r = n;
			while (l < r) {
				int m = (l + r) / 2;
				vector<int> cnt(26, 0);
				for (int i = 0; i < m; i++)
					cnt[s[i] - 'a']++;

				bool ok = true;
				for (int i = 0; i < min(n / 2, n - m); i++) {
					char c = s[n - i - 1];
					if (i < m) {
						ok &= (cnt[c - 'a'] > 0);
						cnt[c - 'a']--;
					} else {
						ok &= (c == s[i]);
					}
				}
				if (ok)
					r = m;
				else
					l = m + 1;
			}
			ans = min(ans, l);
			reverse(s.begin(), s.end());
		}
		cout << ans << '\n';
	}
}
