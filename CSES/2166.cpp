#include <bits/stdc++.h>
using namespace std;

struct Node {
	int64_t sum, pref;
};

Node operator+(const Node &lhs, const Node &rhs) {
	return {lhs.sum + rhs.sum, max(lhs.pref, lhs.sum + rhs.pref)};
}

template <typename T>
struct SegmentTree {
	int n;
	vector<T> st;

	SegmentTree(auto &a) {
		n = (int)a.size();
		st.resize(4 << __lg(n));
		build(a, 0, 0, n);
	}

	void build(auto &a, int u, int l, int r) {
		if (r - l == 1) {
			st[u] = {a[l], a[l]};
			return;
		}
		int m = (l + r) / 2;
		build(a, u * 2 + 1, l, m);
		build(a, u * 2 + 2, m, r);
		st[u] = st[u * 2 + 1] + st[u * 2 + 2];
	}

	void update(int pos, T x, int u, int l, int r) {
		int m = (l + r) / 2;
		if (r - l == 1) {
			st[u] = x;
			return;
		}

		if (pos < m) {
			update(pos, x, u * 2 + 1, l, m);
		} else {
			update(pos, x, u * 2 + 2, m, r);
		}
		st[u] = st[u * 2 + 1] + st[u * 2 + 2];
	}

	T query(int ql, int qr, int u, int l, int r) {
		if (qr <= l || r <= ql) {
			return {0, 0};
		}
		if (ql <= l && r <= qr) {
			return st[u];
		}
		int m = (l + r) / 2;
		return query(ql, qr, u * 2 + 1, l, m) + query(ql, qr, u * 2 + 2, m, r);
	}

	void update(int pos, T x) {
		update(pos, x, 0, 0, n);
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
	vector<int> x(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	SegmentTree<Node> st(x);
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int k, u;
			cin >> k >> u;
			k--;
			st.update(k, {u, u});
		} else {
			int a, b;
			cin >> a >> b;
			a--;
			cout << max((int64_t)0, st.query(a, b).pref) << '\n';
		}
	}
}
