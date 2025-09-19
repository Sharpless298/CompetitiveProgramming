#include <bits/stdc++.h>
using namespace std;

struct DSU {
	vector<int> parent, sz;

	DSU(int _n) {
		parent.resize(_n);
		iota(parent.begin(), parent.end(), 0);
		sz.assign(_n, 1);
	}

	int find(int x) {
		return parent[x] == x ? x : parent[x] = find(parent[x]);
	}
	bool unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) {
			return false;
		}
		if (sz[x] > sz[y]) {
			swap(x, y);
		}
		parent[x] = y;
		sz[y] += sz[x];
		return true;
	}
};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<int> x(m), y(m);
		for (int i = 0; i < m; i++) {
			cin >> x[i] >> y[i];
			x[i]--, y[i]--;
		}

		int ans = 0;
		DSU dsu(n);
		for (int i = 0; i < m; i++) {
			if (x[i] == y[i]) {
				continue;
			}

			if (dsu.unite(x[i], y[i])) {
				ans++;
			} else {
				ans += 2;
			}
		}

		cout << ans << '\n';
	}
}
