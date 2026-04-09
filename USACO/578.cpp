#include <bits/stdc++.h>
using namespace std;

struct Node {
	int64_t mn, sum;
};

Node operator+(const Node &lhs, const Node &rhs) {
	return {min(lhs.mn, rhs.mn), lhs.sum + rhs.sum};
}

template <typename T>
struct SegmentTree {
	int n;
	vector<T> st;
	vector<int64_t> lazy;

	SegmentTree(int _n) {
		n = _n;
		st.assign(4 << __lg(n), 0);
		lazy.assign(4 << __lg(n), 0);
	}

	SegmentTree(auto &a) {
		n = (int)a.size();
		st.resize(4 << __lg(n));
		lazy.assign(4 << __lg(n), 0);
		build(a, 0, 0, n);
	}

	void push(int u, int l, int r) {
		if (lazy[u]) {
			st[u].mn += lazy[u];
			st[u].sum += (r - l) * lazy[u];
			if (r - l > 1) {
				lazy[u * 2 + 1] += lazy[u];
				lazy[u * 2 + 2] += lazy[u];
			}
			lazy[u] = 0;
		}
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

	void update(int ql, int qr, int64_t x, int u, int l, int r) {
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
			return {1LL << 60 , 0};
		}
		if (ql <= l && r <= qr) {
			return st[u];
		}
		int m = (l + r) / 2;
		return query(ql, qr, u * 2 + 1, l, m) + query(ql, qr, u * 2 + 2, m, r);
	}

	void update(int l, int r, int64_t x) {
		update(l, r, x, 0, 0, n);
	}

	T query(int l, int r) {
		return query(l, r, 0, 0, n);
	}
};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);

	int n, q;
	cin >> n >> q;
	vector<int> ary(n);
	for (int i = 0; i < n; i++) {
		cin >> ary[i];
	}
	SegmentTree<Node> st(ary);
	while (q--) {
		char ch;
		cin >> ch;
		int a, b;
		cin >> a >> b;
		a--;
		if (ch == 'M') {
			cout << st.query(a, b).mn << '\n';
		} else if (ch == 'P') {
			int c;
			cin >> c;
			st.update(a, b, c);
		} else {
			cout << st.query(a, b).sum << '\n';
		}
	}
}
