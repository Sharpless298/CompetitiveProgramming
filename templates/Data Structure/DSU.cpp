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
		if (x == y)
			return false;

		if (sz[x] > sz[y])
			swap(x, y);
		parent[x] = y;
		sz[y] += sz[x];
		return true;
	}
};
