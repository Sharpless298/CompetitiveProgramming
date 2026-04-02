#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct SegmentTree {
	int n;
	vector<T> st;
	vector<int64_t> lazy;
	vector<int64_t> lazy2;

	SegmentTree(int _n) {
		n = _n;
		st.assign(4 << __lg(n), 0);
		lazy.assign(4 << __lg(n), 0x3f3f3f3f);
		lazy2.assign(4 << __lg(n), 0);
	}

	SegmentTree(auto &a) {
		n = (int)a.size();
		st.resize(4 * n);
		lazy.assign(4 * n, 0x3f3f3f3f);
		lazy2.assign(4 * n, 0);
		build(a, 0, 0, n);
	}

	void push(int u, int l, int r) {
		if (lazy[u] != 0x3f3f3f3f) {
			st[u] = (r - l) * lazy[u];
			if (r - l > 1) {
				lazy[u * 2 + 1] = lazy[u];
				lazy[u * 2 + 2] = lazy[u];
				lazy2[u * 2 + 1] = 0;
				lazy2[u * 2 + 2] = 0;
			}
			lazy[u] = 0x3f3f3f3f;
		}
		if (lazy2[u]) {
			st[u] += (r - l) * lazy2[u];
			if (r - l > 1) {
				lazy2[u * 2 + 1] += lazy2[u];
				lazy2[u * 2 + 2] += lazy2[u];
			}
			lazy2[u] = 0;
		}
	}

	void build(auto &a, int u, int l, int r) {
		if (r - l == 1) {
			st[u] = a[l];
			return;
		}
		int m = (l + r) / 2;
		build(a, u * 2 + 1, l, m);
		build(a, u * 2 + 2, m, r);
		st[u] = st[u * 2 + 1] + st[u * 2 + 2];
	}

	void set(int ql, int qr, T x, int u, int l, int r) {
		push(u, l, r);
		if (qr <= l || r <= ql) {
			return;
		}
		if (ql <= l && r <= qr) {
			lazy[u] = x;
			lazy2[u] = 0;
			push(u, l, r);
			return;
		}
		int m = (l + r) / 2;
		set(ql, qr, x, u * 2 + 1, l, m);
		set(ql, qr, x, u * 2 + 2, m, r);
		st[u] = st[u * 2 + 1] + st[u * 2 + 2];
	}

	void update(int ql, int qr, T x, int u, int l, int r) {
		push(u, l, r);
		if (qr <= l || r <= ql) {
			return;
		}
		if (ql <= l && r <= qr) {
			lazy2[u] += x;
			push(u, l, r);
			return;
		}
		int m = (l + r) / 2;
		update(ql, qr, x, u * 2 + 1, l, m);
		update(ql, qr, x, u * 2 + 2, m, r);
		st[u] = st[u * 2 + 1] + st[u * 2 + 2];
	}

	T query(int ql, int qr, int u, int l, int r) {
		push(u, l, r);
		if (qr <= l || r <= ql) {
			return 0;
		}
		if (ql <= l && r <= qr) {
			return st[u];
		}
		int m = (l + r) / 2;
		return query(ql, qr, u * 2 + 1, l, m) + query(ql, qr, u * 2 + 2, m, r);
	}

	void set(int l, int r, T x) {
		set(l, r, x, 0, 0, n);
	}

	void update(int l, int r, T x) {
		update(l, r, x, 0, 0, n);
	}

	T query(int l, int r) {
		return query(l, r, 0, 0, n);
	}
};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	SegmentTree<int64_t> st(a);
	int q;
	cin >> q;
	while (q--) {
		int v;
		cin >> v;
		if (v == 1) {
			int x, y, k;
			cin >> x >> y >> k;
			x--;
			st.update(x, y, k);
		} else {
			int x, y;
			cin >> x >> y;
			x--;
			cout << st.query(x, y) << '\n';
		}
	}
}
