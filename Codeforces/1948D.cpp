#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;

		int ans = 0;
		for (int i = 1; i <= (int)s.size() / 2; i++) {
			int cnt = 0;
			for (int j = 0; j < (int)s.size() - i; j++) {
				if (s[j] == s[j + i] || s[j] == '?' || s[j + i] == '?') {
					cnt++;
				} else {
					cnt = 0;
				}

				if (cnt == i) {
					ans = max(ans, i);
					break;
				}
			}
		}
		ans *= 2;
		cout << ans << '\n';
	}
}
