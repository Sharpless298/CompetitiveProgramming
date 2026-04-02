#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct SegmentTree {
	int n;
	vector<T> st, a;

	SegmentTree(int _n) {
		n = _n;
		st.assign(4 * n, INT_MAX);
	}

	SegmentTree(vector<T> &_a) {
		a = _a;
		n = (int)a.size();
		st.resize(4 * n);
		build(a, 0, 0, n);
	}

	void build(int u, int l, int r) {
		if (r - l == 1) {
			st[u] = a[l];
			return;
		}
		int m = (l + r) / 2;
		build(a, u * 2 + 1, l, m);
		build(a, u * 2 + 2, m, r);
		st[u] = min(st[u * 2 + 1], st[u * 2 + 2]);
	}

	void update(int pos, T x, int u, int l, int r) {
		if (r - l == 1) {
			st[u] = min(st[u], x);
			return;
		}
		int m = (l + r) / 2;
		pos < m ? update(pos, x, u * 2 + 1, l, m) : update(pos, x, u * 2 + 2, m, r);
		st[u] = min(st[u * 2 + 1], st[u * 2 + 2]);
	}

	T query(int ql, int qr, int u, int l, int r) {
		if (qr <= l || r <= ql) {
			return INT_MAX;
		}
		if (ql <= l && r <= qr) {
			return st[u];
		}
		int m = (l + r) / 2;
		return min(query(ql, qr, u * 2 + 1, l, m), query(ql, qr, u * 2 + 2, m, r));
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

	freopen("boards.in", "r", stdin);
	freopen("boards.out", "w", stdout);

	int n, p;
	cin >> n >> p;
	vector<array<int, 4>> v;
	vector<int> y;
	for (int i = 0; i < p; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		v.push_back({x1, y1, i, 1});
		v.push_back({x2, y2, i, 0});
		y.push_back(y1);
		y.push_back(y2);
	}
	sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
		if (a[0] == b[0]) {
			return a[1] < b[1];
		}
		return a[0] < b[0];
	});
	sort(y.begin(), y.end());
	auto undo = [&](int yy) -> int {
		return (int)(lower_bound(y.begin(), y.end(), yy) - y.begin());
	};

	vector<int> dp(p);
	SegmentTree<int> st(p * 2);
	st.update(0, 0);
	for (auto i : v) {
		if (i[3]) {
			dp[i[2]] = i[0] + i[1] + st.query(0, undo(i[1]) + 1);
		} else {
			st.update(undo(i[1]), dp[i[2]] - i[0] - i[1]);
		}
	}
	cout << st.query(0, 2 * p) + 2 * n << '\n';
}
