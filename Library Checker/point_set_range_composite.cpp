#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 998244353;

struct Node {
	int64_t a, b;
};
Node operator+(const Node &lhs, const Node &rhs) {
	return {lhs.a * rhs.a % MOD, (rhs.a * lhs.b + rhs.b) % MOD};
}

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

	void update(int p, T x, int u, int l, int r) {
		if (r - l == 1) {
			st[u] = x;
			return;
		}
		int m = (l + r) / 2;
		p < m ? update(p, x, u * 2 + 1, l, m) : update(p, x, u * 2 + 2, m, r);
		st[u] = st[u * 2 + 1] + st[u * 2 + 2];
	}

	T query(int ql, int qr, int u, int l, int r) {
		if (qr <= l || r <= ql) {
			return Node{1, 0};
		}
		if (ql <= l && r <= qr) {
			return st[u];
		}
		int m = (l + r) / 2;
		return query(ql, qr, u * 2 + 1, l, m) + query(ql, qr, u * 2 + 2, m, r);
	}

	void update(int p, T x) {
		update(p, x, 0, 0, n);
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
	vector<Node> f(n);
	for (int i = 0; i < n; i++) {
		cin >> f[i].a >> f[i].b;
	}

	SegmentTree<Node> st(f);
	while (q--) {
		int type;
		cin >> type;
		if (type == 0) {
			int p, c, d;
			cin >> p >> c >> d;
			st.update(p, {c, d});
		} else {
			int l, r, x;
			cin >> l >> r >> x;
			Node ret = st.query(l, r);
			cout << (ret.a * x + ret.b) % MOD << '\n';
		}
	}
}
