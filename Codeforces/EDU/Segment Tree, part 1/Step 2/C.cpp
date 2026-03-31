#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct SegmentTree {
	int n;
	vector<T> st;

	SegmentTree(int _n) {
		n = _n;
		st.assign(4 * n, T());
	}

	SegmentTree(vector<T> &a) {
		n = (int)a.size();
		st.resize(4 * n);
		build(a, 0, 0, n);
	}
	
	void pull(int u) {
		st[u] = max(st[u * 2 + 1], st[u * 2 + 2]);
	}

	void build(vector<T> &a, int u, int l, int r) {
		if (r - l == 1) {
			st[u] = a[l];
			return;
		}
		int m = (l + r) / 2;
		build(a, u * 2 + 1, l, m);
		build(a, u * 2 + 2, m, r);
		pull(u);
	}

	void update(int ql, int qr, T x, int u, int l, int r) {
		if (qr <= l || r <= ql) {
			return;
		}
		if (ql <= l && r <= qr) {
			st[u] = x;
			return;
		}
		int m = (l + r) / 2;
		update(ql, qr, x, u * 2 + 1, l, m);
		update(ql, qr, x, u * 2 + 2, m, r);
		pull(u);
	}

	T query(int x, int u, int l, int r) {
		if (r - l == 1) {
			return l;
		}
		int m = (l + r) / 2;
		if (x <= st[u * 2 + 1]) {
			return query(x, u * 2 + 1, l, m);
		} else {
			return query(x, u * 2 + 2, m, r);
		}
	}

	void update(int l, int r, T x) {
		update(l, r, x, 0, 0, n);
	}

	T query(int x) {
		return query(x, 0, 0, n);
	}
};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	a[n] = 1 << 30;
	SegmentTree<int> st(a);
	while (m--) {
		int op;
		cin >> op;
		if (op == 1) {
			int i, x;
			cin >> i >> x;
			st.update(i, i + 1, x);
		} else {
			int x;
			cin >> x;
			int ret = st.query(x);
			cout << (ret == n ? -1 : ret) << '\n';
		}
	}
}
