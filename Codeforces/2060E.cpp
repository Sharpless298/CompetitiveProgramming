#include <bits/stdc++.h>
using namespace std;

struct DSU {
	int cc;
	vector<int> parent, sizes;

	DSU(int n) {
		cc = n;
		parent.resize(n);
		iota(parent.begin(), parent.end(), 0);
		sizes.assign(n, 1);
	}
	int find(int x) {
		return parent[x] == x ? x : parent[x] = find(parent[x]);
	}
	bool unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y)
			return false;

		cc--;
		if (sizes[x] > sizes[y])
			swap(x, y);
		parent[x] = y;
		sizes[y] += sizes[x];
		return true;
	}
};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, m1, m2;
		cin >> n >> m1 >> m2;
		DSU dsu1(n), dsu2(n);
		vector<pair<int, int>> E;
		for (int i = 0; i < m1; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			E.push_back({u, v});
		}
		for (int i = 0; i < m2; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			dsu2.unite(u, v);
		}

		int ans = 0;
		for (auto p : E) {
			if (dsu2.find(p.first) != dsu2.find(p.second))
				ans++;
			else
				dsu1.unite(p.first, p.second);
		}

		cout << ans + dsu1.cc - dsu2.cc << '\n';
	}
}
