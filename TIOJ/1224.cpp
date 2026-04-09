#include <bits/stdc++.h>
using namespace std;

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

	void update(int ql, int qr, T x, int u, int l, int r) {
		if (qr <= l || r <= ql) {
			return;
		}
		if (ql <= l && r <= qr) {
			lazy[u] += x;
			return;
		}
		int m = (l + r) / 2;
		update(ql, qr, x, u * 2 + 1, l, m);
		update(ql, qr, x, u * 2 + 2, m, r);
		st[u] = (lazy[u * 2 + 1] ? m - l : st[u * 2 + 1]) + 
			(lazy[u * 2 + 2] ? r - m : st[u * 2 + 2]);
	}

	void update(int l, int r, T x) {
		update(l, r, x, 0, 0, n);
	}
};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<array<int, 4>> a;
	for (int i = 0; i < n; i++) {
		int l, r, d, u;
		cin >> l >> r >> d >> u;
		a.push_back({l, r, d, 1});
		a.push_back({l, r, u, -1});
	}
	sort(a.begin(), a.end(), [](const auto &x, const auto &y) {
		return x[2] < y[2];
	});
	SegmentTree<int64_t> st(1000001);
	int64_t ans = 0;
	int y0 = 0;
	for (auto [l, r, y, t] : a) {
		ans += (int64_t)(y - y0) * st.st[0];
		st.update(l, r, t);
		y0 = y;
	}
	cout << ans << '\n';
}
