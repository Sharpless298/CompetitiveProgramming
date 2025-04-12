#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

struct Node {
	lli sum, pref, suf, mx;
};

int n, q;
vector<int> a;
vector<Node> seg;

void merge(Node &cur, Node &l, Node &r) {
	cur.sum = l.sum + r.sum;
	cur.pref = max(l.pref, l.sum + r.pref);
	cur.suf = max(r.suf, l.suf + r.sum);
	cur.mx = max({l.mx, r.mx, l.suf + r.pref});
}

void build(int id = 0, int L = 0, int R = n) {
	if (R - L == 1) {
		seg[id] = {a[L], a[L], a[L], a[L]};
		return;
	}

	int M = (L + R) / 2;
	build(id * 2 + 1, L, M);
	build(id * 2 + 2, M, R);
	merge(seg[id], seg[id * 2 + 1], seg[id * 2 + 2]);
}

void update(int x, int v, int id = 0, int L = 0, int R = n) {
	if (R - L == 1) {
		seg[id] = {v, v, v, v};
		return;
	}

	int M = (L + R) / 2;
	if (x < M)
		update(x, v, id * 2 + 1, L, M);
	else
		update(x, v, id * 2 + 2, M, R);

	merge(seg[id], seg[id * 2 + 1], seg[id * 2 + 2]);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> q;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	seg.resize(4 * n);
	build();

	cout << max(seg[0].mx, 0LL) << '\n';
	while (q--) {
		int x, v;
		cin >> x >> v;

		update(x, v);
		cout << max(seg[0].mx, 0LL) << '\n';
	}
}
