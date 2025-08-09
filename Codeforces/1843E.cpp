#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> a(n);
		for (int i = 0; i < m; i++) {
			cin >> a[i].first >> a[i].second;
			a[i].first--;
		}

		int q;
		cin >> q;
		vector<int> order(q);
		for (int &i : order) cin >> i, i--;
		int l = 0, r = q + 1;
		while (l < r) {
			int mid = (l + r) >> 1;

			vector<int> b(n);
			for (int i = 0; i < mid; i++)
				b[order[i]] = 1;
			vector<int> pref(n + 1, 0);
			for (int i = 0; i < n; i++)
				pref[i + 1] = pref[i] + b[i];

			bool f = true;
			for (pair<int, int> &p : a) {
				if (pref[p.second] - pref[p.first] > (p.second - p.first) / 2) {
					f = false;
					break;
				}
			}

			if (f) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}

		cout << (l == q + 1 ? -1 : l) << '\n';
	}
}
