#include <bits/stdc++.h>
using namespace std;

struct Node {
	int64_t sum, lsum, rsum, mx;
	Node operator+(const Node &rhs) const {
		return {sum + rhs.sum,
				max(lsum, sum + rhs.lsum),
				max(rhs.rsum, rsum + rhs.sum),
				max({mx, rhs.mx, rsum + rhs.lsum})};
	}
};

template <typename T>
struct SegmentTree {
	int n;
	vector<T> segtree;

	SegmentTree(int _n) {
		n = _n;
		segtree.assign(4 * n, T());
	}

	SegmentTree(vector<T> &a) {
		n = (int)a.size();
		segtree.resize(4 * n);
		build(a, 0, 0, n);
	}

	void build(vector<T> &a, int u, int l, int r) {
		if (r - l == 1) {
			segtree[u] = a[l];
			return;
		}
		int m = (l + r) / 2;
		build(a, u * 2 + 1, l, m);
		build(a, u * 2 + 2, m, r);
		segtree[u] = segtree[u * 2 + 1] + segtree[u * 2 + 2];
	}

	void update(int ql, int qr, T val, int u, int l, int r) {
		if (qr <= l || r <= ql) {
			return;
		}
		if (ql <= l && r <= qr) {
			segtree[u] = val;
			return;
		}
		int m = (l + r) / 2;
		update(ql, qr, val, u * 2 + 1, l, m);
		update(ql, qr, val, u * 2 + 2, m, r);
		segtree[u] = segtree[u * 2 + 1] + segtree[u * 2 + 2];
	}

	void update(int l, int r, T val) {
		update(l, r, val, 0, 0, n);
	}
};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<Node> a(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[i] = {x, x, x, x};
	}

	SegmentTree st(a);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		st.update(x, x + 1, (Node){y, y, y, y});
		cout << max(int64_t(0), st.segtree[0].mx) << '\n';
	}
}
