#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;

		int ans = 0;
		vector<bool> b(n);
		for (int i = 0, j = 1; i < n; ) {
			ans++;

			while (j < n && s[j] != s[j - 1]) {
				j++;
			}
			if (j != n) {
				b[j] = true;
				j++;

				char c = s[i];
				while (i < n && (b[i] || c == s[i])) {
					i++;
				}
				if (j < i) {
					j = i + 1;
				}
			} else {
				char c = s[i];
				while (i < n && (b[i] || c == s[i])) {
					i++;
				}
				c = s[i];
				while (i < n && (b[i] || c == s[i])) {
					i++;
				}
			}
		}

		cout << ans << '\n';
	}
}
