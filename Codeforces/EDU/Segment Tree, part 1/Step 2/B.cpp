#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct SegmentTree {
	int n;
	vector<T> st;

	SegmentTree(int _n) {
		n = _n;
		st.assign(4 << __lg(n), T());
	}

	SegmentTree(vector<T> &a) {
		n = (int)a.size();
		st.resize(4 << __lg(n));
		build(a, 0, 0, n);
	}

	void build(vector<T> &a, int u, int l, int r) {
		if (r - l == 1) {
			st[u] = a[l];
			return;
		}
		int m = (l + r) / 2;
		build(a, u * 2 + 1, l, m);
		build(a, u * 2 + 2, m, r);
		st[u] = st[u * 2 + 1] + st[u * 2 + 2];
	}

	void update(int ql, int qr, int u, int l, int r) {
		if (qr <= l || r <= ql) {
			return;
		}
		if (ql <= l && r <= qr) {
			st[u] ^= 1;
			return;
		}
		int m = (l + r) / 2;
		update(ql, qr, u * 2 + 1, l, m);
		update(ql, qr, u * 2 + 2, m, r);
		st[u] = st[u * 2 + 1] + st[u * 2 + 2];
	}

	T query(int k, int u, int l, int r) {
		if (k == 0 && r - l == 1) {
			return l;
		}
		int m = (l + r) / 2;
		if (k < st[u * 2 + 1]) {
			return query(k, u * 2 + 1, l, m);
		} else {
			return query(k - st[u * 2 + 1], u * 2 + 2, m, r);
		}
	}

	void update(int l, int r) {
		update(l, r, 0, 0, n);
	}

	T query(int k) {
		return query(k, 0, 0, n);
	}
};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	SegmentTree st(a);
	while (m--) {
		int op;
		cin >> op;
		if (op == 1) {
			int i;
			cin >> i;
			st.update(i, i + 1);
		} else {
			int k;
			cin >> k;
			cout << st.query(k) << '\n';
		}
	}
}
