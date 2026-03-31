#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;

		string ss = s, tt = t;
		for (int i = 0; i < n - 2; i++) {
			if (ss[i] == '0' && ss[i + 2] == '0') {
				tt[i + 1] = '1';
			}
		}
		for (int i = 0; i < n - 2; i++) {
			if (tt[i] == '1' && tt[i + 2] == '1') {
				ss[i + 1] = '1';
			}
		}
		vector<int> pref(n + 1);
		for (int i = 0; i < n; i++) {
			pref[i + 1] = pref[i] + (ss[i] == '1');
		}

		int q;
		cin >> q;
		while (q--) {
			int l, r;
			cin >> l >> r;
			l--;
			if (r - l <= 2) {
				int ans = 0;
				for (int i = l; i < r; i++) {
					ans += (s[i] == '1');
				}
				cout << ans << '\n';
			} else {
				int ans = pref[r] - pref[l];
				r--;
				if (s[l] == '0' && ss[l] == '1') {
					ans--;
				}
				if (r - l + 1 == 3) {
					if (s[l + 1] == '0' && ss[l + 1] == '1' && (t[l] == '0' || t[l + 2] == '0')) {
						ans--;
					}
				} else {
					if (s[l + 1] == '0' && ss[l + 1] == '1' && t[l] == '0') {
						ans--;
					}
					if (s[r - 1] == '0' && ss[r - 1] == '1' && t[r] == '0') {
						ans--;
					}
				}
				if (s[r] == '0' && ss[r] == '1') {
					ans--;
				}
				cout << ans << '\n';
			}
		}
	}
}
