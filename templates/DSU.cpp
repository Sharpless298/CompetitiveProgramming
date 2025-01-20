struct DSU {
	vector<int> parent, sizes;

	DSU(int n) {
		parent.resize(n);
		iota(parent.begin(), parent.end(), 0);
		sizes.assign(n, 1);
	}
	int find(int x) {
		return parent[x]==x ? x : parent[x] = find(parent[x]);
	}
	bool unite(int x, int y) {
		x = find(x), y = find(y);
		if(x == y) return false;

		if(sizes[x] > sizes[y]) swap(x, y);
		parent[x] = y;
		sizes[y] += sizes[x];
		return true;
	}
};
