#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct SegmentTree {
	int n;
	vector<T> st;
	vector<T> lazy;

	SegmentTree(int _n) {
		n = _n;
		st.assign(4 * n, T());
		lazy.assign(4 * n, T());
	}

	SegmentTree(vector<T> &a) {
		n = (int)a.size();
		st.resize(4 * n);
		lazy.assign(4 * n, T());
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
		pull(u);
	}

	T query(int x, int u, int l, int r) {
		push(u, l, r);
		if (r - l == 1) {
			return l;
		}
		int m = (l + r) / 2;
		if (st[u * 2 + 1] >= x) {
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
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	SegmentTree<int> st(a);

	while (m--) {
		int x;
		cin >> x;
		if (st.st[0] >= x) {
			int ans = st.query(x);
			st.update(ans, ans + 1, -x);
			cout << ans + 1;
		} else {
			cout << 0;
		}
		cout << " \n"[m == 0];
	}
}
