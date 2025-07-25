#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	map<char, int> mp;
	mp['B'] = 1 << 0;
	mp['G'] = 1 << 1;
	mp['R'] = 1 << 2;
	mp['Y'] = 1 << 3;

	int T;
	cin >> T;
	while (T--) {
		int n, q;
		cin >> n >> q;
		vector<int> a(n);
		vector<vector<int>> b(16);
		for (int i = 0; i < n; i++) {
			char c, d;
			cin >> c >> d;
			a[i] = (mp[c] | mp[d]);
			b[a[i]].push_back(i);
		}

		while (q--) {
			int x, y;
			cin >> x >> y;
			x--, y--;

			if (a[x] & a[y]) {
				cout << abs(x - y) << '\n';
			} else {
				int ans = 0x3f3f3f3f;
				for (int i = 0; i < 16; i++) {
					if (i == 1 || b[i].empty() || i == a[x] || i == a[y]) continue;

					auto it = lower_bound(b[i].begin(), b[i].end(), x);
					if (it != b[i].end()) ans = min(ans, abs(*it - x) + abs(*it - y));
					if (it != b[i].begin()) ans = min(ans, abs(*prev(it) - x) + abs(*prev(it) - y));
				}
				cout << (ans == 0x3f3f3f3f ? -1 : ans) << '\n';
			}
		}
	}
}
