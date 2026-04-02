#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct SegmentTree {
	int n;
	vector<T> st;
	vector<int64_t> lazy_k, lazy_c;

	SegmentTree(auto &a) {
		n = (int)a.size();
		st.resize(4 * n);
		lazy_k.assign(4 * n, 0);
		lazy_c.assign(4 * n, 0);
		build(a, 0, 0, n);
	}

	void push(int u, int l, int r) {
		if (lazy_k[u] != 0 || lazy_c[u] != 0) {
			st[u] += lazy_k[u] * (l + r - 1) * (r - l) / 2 + lazy_c[u] * (r - l);
			if (r - l > 1) {
				lazy_k[u * 2 + 1] += lazy_k[u];
				lazy_c[u * 2 + 1] += lazy_c[u];
				lazy_k[u * 2 + 2] += lazy_k[u];
				lazy_c[u * 2 + 2] += lazy_c[u];
			}
			lazy_k[u] = lazy_c[u] = 0;
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

	void update(int ql, int qr, int pos, int u, int l, int r) {
		push(u, l, r);
		if (qr <= l || r <= ql) {
			return;
		}
		if (ql <= l && r <= qr) {
			lazy_k[u]++;
			lazy_c[u] += (1 - pos);
			push(u, l, r);
			return;
		}
		int m = (l + r) / 2;
		update(ql, qr, pos, u * 2 + 1, l, m);
		update(ql, qr, pos, u * 2 + 2, m, r);
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

	void update(int l, int r, int pos) {
		update(l, r, pos, 0, 0, n);
	}

	T query(int l, int r) {
		return query(l, r, 0, 0, n);
	}
};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;
	vector<int64_t> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	SegmentTree<int64_t> st(a);
	while (q--) {
		int type, x, y;
		cin >> type >> x >> y;
		x--;
		if (type == 1) {
			st.update(x, y, x);
		} else {
			cout << st.query(x, y) << '\n';
		}
	}
}
