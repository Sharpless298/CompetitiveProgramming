#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

template <typename T>
struct SegmentTree {
	int n;
	vector<T> st;
	vector<int64_t> lazy;
	vector<int64_t> lazy2;
	vector<int64_t> lazy3;

	SegmentTree(const auto &a) {
		n = (int)a.size();
		st.resize(4 << __lg(n));
		lazy.assign(4 << __lg(n), 0x3f3f3f3f);
		lazy2.assign(4 << __lg(n), 0);
		lazy3.assign(4 << __lg(n), 1);
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
		if (lazy2[u] != 0 || lazy3[u] != 1) {
			st[u] = (st[u] * lazy3[u] % MOD + (r - l) * lazy2[u]) % MOD;
			if (r - l > 1) {
				lazy3[u * 2 + 1] = (lazy3[u * 2 + 1] * lazy3[u]) % MOD;
				lazy3[u * 2 + 2] = (lazy3[u * 2 + 2] * lazy3[u]) % MOD;
				lazy2[u * 2 + 1] = (lazy2[u * 2 + 1] * lazy3[u]) % MOD;
				lazy2[u * 2 + 2] = (lazy2[u * 2 + 2] * lazy3[u]) % MOD;

				lazy2[u * 2 + 1] = (lazy2[u * 2 + 1] + lazy2[u]) % MOD;
				lazy2[u * 2 + 2] = (lazy2[u * 2 + 2] + lazy2[u]) % MOD;
			}
			lazy2[u] = 0;
			lazy3[u] = 1;
		}
	}

	void build(const auto &a, int u, int l, int r) {
		if (r - l == 1) {
			st[u] = a[l];
			return;
		}
		int m = (l + r) / 2;
		build(a, u * 2 + 1, l, m);
		build(a, u * 2 + 2, m, r);
		st[u] = (st[u * 2 + 1] + st[u * 2 + 2]) % MOD;
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
		st[u] = (st[u * 2 + 1] + st[u * 2 + 2]) % MOD;
	}

	void update(int ql, int qr, T b, T c, int u, int l, int r) {
		push(u, l, r);
		if (qr <= l || r <= ql) {
			return;
		}
		if (ql <= l && r <= qr) {
			lazy2[u] = (lazy2[u] * b) % MOD;
			lazy3[u] = (lazy3[u] * b) % MOD;
			lazy2[u] = (lazy2[u] + c) % MOD;
			push(u, l, r);
			return;
		}
		int m = (l + r) / 2;
		update(ql, qr, b, c, u * 2 + 1, l, m);
		update(ql, qr, b, c, u * 2 + 2, m, r);
		st[u] = (st[u * 2 + 1] + st[u * 2 + 2]) % MOD;
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
		return (query(ql, qr, u * 2 + 1, l, m) + query(ql, qr, u * 2 + 2, m, r)) % MOD;
	}

	void set(int l, int r, T x) {
		set(l, r, x, 0, 0, n);
	}

	void update(int l, int r, T b, T c) {
		update(l, r, b, c, 0, 0, n);
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
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	SegmentTree<int64_t> st(a);
	while (q--) {
		int type, l, r;
		cin >> type >> l >> r;
		if (type == 0) {
			int b, c;
			cin >> b >> c;
			st.update(l, r, b, c);
		} else {
			cout << st.query(l, r) << '\n';
		}
	}
}
