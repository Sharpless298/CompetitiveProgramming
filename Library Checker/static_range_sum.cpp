#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct SegmentTree {
	int n;
	vector<T> st, tag;

	SegmentTree(int _n) : n(_n) {
		st.resize(n << 1);
		tag.resize(n);
	}

	SegmentTree(auto &a) : n((int)a.size()) {
		st.resize(n << 1);
		tag.resize(n);
		for (int i = 0; i < n; i++) {
			st[i + n] = a[i];
		}
		for (int i = n - 1; i > 0; i--) {
			st[i] = st[i << 1] + st[i << 1 | 1];
		}
	}

	void add(int u, T d, int h) {
		st[u] += d << h;
		if (u < n) {
			tag[u] += d;
		}
	}

	void push(int u) {
		for (int h = __lg(n); h >= 0; h--) {
			int v = u >> h;
			add(v, tag[v >> 1], h);
			add(v ^ 1, tag[v >> 1], h);
			tag[v >> 1] = 0;
		}
	}

	void pull(int u) {
		for (int h = 1; u > 1; h++, u >>= 1) {
			st[u >> 1] = st[u] + st[u ^ 1] + (tag[u >> 1] << h);
		}
	}

	void update(int l, int r, T k) {
		l++, r++;
		int tl = l, tr = r, h = 0;
		push(l + n), push(r - 1 + n);
		for (l += n, r += n; l < r; l >>= 1, r >>= 1, h++) {
			if (l & 1) {
				upd(l++, k, h);
			}
			if (r & 1) {
				upd(--r, k, h);
			}
		}
		pull(tl + n), pull(tr - 1 + n);
	}

	T query(int l, int r) {
		T sum = 0;
		push(l + n), push(r - 1 + n);
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) {
				sum += st[l++];
			}
			if (r & 1) {
				sum += st[--r];
			}
		}
		return sum;
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

	SegmentTree<long long> st(a);

	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << st.query(l, r) << '\n';
	}
}
