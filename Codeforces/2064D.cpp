#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		reverse(a.begin(), a.end());
		array<vector<int>, 30> pos;
		vector<vector<int>> pref(30, vector<int>(n + 1));
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < n; j++) {
				int x = (a[j] >> i & 1);
				if (x) {
					pos[i].push_back(j);
				}
				pref[i][j + 1] = pref[i][j] ^ x;
			}
		}

		for (int j = 0; j < q; j++) {
			int x;
			cin >> x;

			int ans = n, cur = 0;
			for (int i = 29; i >= 0; i--) {
				int y = (x >> i & 1);
				auto it = lower_bound(pos[i].begin(), pos[i].end(), cur);
				if (pref[i][cur] ^ y) {
					if (it != pos[i].end()) {
						cur = *it;
						++it;
					} else {
						break;
					}
					if (it != pos[i].end()) {
						ans = min(ans, *it);
					}
				} else {
					if (it != pos[i].end()) {
						ans = min(ans, *it);
					}
				}
			}
			cout << ans << " \n"[j + 1 == q];
		}
	}
}
