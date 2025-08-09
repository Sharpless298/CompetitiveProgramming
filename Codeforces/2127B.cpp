#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, x;
		cin >> n >> x, x--;
		string s;
		cin >> s;

		int l = x, r = x;
		while (l > 0 && s[l - 1] == '.') l--;
		while (r < n - 1 && s[r + 1] == '.') r++;

		if (l + 1 < n - r) {
			l = x;
		} else {
			r = x;
		}
		cout << min(l + 1, n - r) << '\n';
	}
}
