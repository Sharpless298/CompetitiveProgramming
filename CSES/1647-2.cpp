#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<pair<int, int>> query(q);
	for (int i = 0; i < q; i++) {
		cin >> query[i].first >> query[i].second;
		query[i].first--;
	}
	
	vector<int> lef(n + 1), rig(n + 1), ans(q);
	auto f = [&](auto &&self, int l, int r, vector<int> v) -> void {
		if (v.size() == 0 || l >= r) {
			return;
		}
		if (r - l == 1) {
			for (int i : v) {
				ans[i] = a[l];
			}
			return;
		}

		int m = (l + r) / 2;
		lef[m - 1] = a[m - 1];
		for (int i = m - 2; i >= l; i--) {
			lef[i] = min(lef[i + 1], a[i]);
		}
		rig[m + 1] = a[m];
		for (int i = m + 1; i < r; i++) {
			rig[i + 1] = min(rig[i], a[i]);
		}
		array<vector<int>, 2> todo;
		for (int i : v) {
			int L = query[i].first, R = query[i].second;
			if (L < m && m < R) {
				ans[i] = min(lef[L], rig[R]);
				continue;
			}
			todo[L >= m].push_back(i);
		}
		self(self, l, m, todo[0]);
		self(self, m, r, todo[1]);
	};
	vector<int> id(q);
	iota(id.begin(), id.end(), 0);
	f(f, 0, n, id);
	for (int i : ans) {
		cout << i << '\n';
	}
}
