#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, m, q;
		cin >> n >> m >> q;

		int l = -1, ml = m, mr = m, r = -1;
		q--;
		{
			int x;
			cin >> x;
			if (x == m) {
				ml = 0x3f3f3f3f, mr = -0x3f3f3f3f;
				l = 1, r = n;
			} else {
				x < ml ? ml-- : mr++;
			}
			int ans = (ml == 0x3f3f3f3f ? 0 : mr - ml + 1);
			if (l != -1 && r != -1) {
				ans += min(l, ml - 1) + n - max(r, mr + 1) + 1;
			}
			cout << min(ans, n) << ' ';
		}
		while (q--) {
			int x;
			cin >> x;

			if (l != -1 && r != -1) {
				if (x > l) {
					l++;
				}
				if (x < r) {
					r--;
				}
			}
			if (ml <= x && x <= mr) {
				if (l == -1 && r == -1) {
					l = 1, r = n;
				}
			} else if (ml != 0x3f3f3f3f) {
				x < ml ? ml-- : mr++;
			}

			int ans = (ml == 0x3f3f3f3f ? 0 : mr - ml + 1);
			if (l != -1 && r != -1) {
				ans += min(l, ml - 1) + n - max(r, mr + 1) + 1;
			}
			cout << min(ans, n) << ' ';
		}
		cout << '\n';
	}
}
