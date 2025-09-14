#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> l(n), r(n);
		for (int i = 0; i < n; i++) {
			cin >> l[i] >> r[i];
		}
		vector<pair<int, int>> v;
		for (int i = 0; i < n; i++) {
			if (l[i] != 1) {
				v.push_back(make_pair(l[i], -1));
				v.push_back(make_pair(r[i], 1));
			}
		}
		sort(v.begin(), v.end());

		int ans = 0, cur = 0, lst = 0;
		for (auto [x, y] : v) {
			cur += y;
			lst = x;
			ans = max(ans, -cur);
		}

		v.clear();
		for (int i = 0; i < n; i++) {
			if (r[i] != m) {
				v.push_back(make_pair(l[i], -1));
				v.push_back(make_pair(r[i], 1));
			}
		}
		sort(v.begin(), v.end());

		cur = lst = 0;
		for (auto [x, y] : v) {
			cur += y;
			lst = x;
			ans = max(ans, -cur);
		}

		cout << ans << '\n';
	}
}
