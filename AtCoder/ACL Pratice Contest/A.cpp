#include <bits/stdc++.h>
using namespace std;

struct DSU {
	vector<int> parent, sizes;

	DSU(int n) {
		parent.resize(n), iota(parent.begin(), parent.end(), 0);
		sizes.assign(n, 1);
	}
	int find(int x) {
		return parent[x] == x ? x : parent[x] = find(parent[x]);
	}
	bool unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y)
			return false;

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

	int n, q;
	cin >> n >> q;
	DSU dsu(n);
	while (q--) {
		int t, u, v;
		cin >> t >> u >> v;
		if (t == 0)
			dsu.unite(u, v);
		else
			cout << (dsu.find(u) == dsu.find(v)) << '\n';
	}
}
