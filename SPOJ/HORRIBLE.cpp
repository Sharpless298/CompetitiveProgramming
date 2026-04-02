#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct SegmentTree {
	int n;
	vector<T> st, a;
	vector<int64_t> lazy;

	SegmentTree(int _n) {
		n = _n;
		st.assign(4 * n, T());
		lazy.assign(4 * n, T());
	}

	SegmentTree(vector<T> &_a) {
		a = _a;
		n = (int)a.size();
		st.resize(4 * n);
		lazy.assign(4 * n, T());
		build(a, 0, 0, n);
	}

	void push(int u, int l, int r) {
		if (lazy[u] != 0) {
			st[u] += (r - l) * lazy[u];
			if (r - l > 1) {
				lazy[u * 2 + 1] += lazy[u];
				lazy[u * 2 + 2] += lazy[u];
			}
			lazy[u] = 0;
		}
	}

	void build(int u, int l, int r) {
		if (r - l == 1) {
			st[u] = a[l];
			return;
		}
		int m = (l + r) / 2;
		build(a, u * 2 + 1, l, m);
		build(a, u * 2 + 2, m, r);
		st[u] = st[u * 2 + 1] + st[u * 2 + 2];
	}

	void update(int ql, int qr, T x, int u, int l, int r) {
		push(u, l, r);
		if (qr <= l || r <= ql) {
			return;
		}
		if (ql <= l && r <= qr) {
			lazy[u] += x;
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

	int t;
	cin >> t;
	while (t--) {
		int n, c;
		cin >> n >> c;

		SegmentTree<int64_t> st(n);
		while (c--) {
			int type;
			cin >> type;
			if (type == 0) {
				int p, q, v;
				cin >> p >> q >> v;
				p--;
				st.update(p, q, v);
			} else {
				int p, q;
				cin >> p >> q;
				p--;
				cout << st.query(p, q) << '\n';
			}
		}
	}
}
