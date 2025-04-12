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

void build(int L = 0, int R = n, int id = 0) {
	if (R - L == 1) {
		seg[id] = {a[L], a[L], a[L], a[L]};
		return;
	}

	int M = (L + R) / 2;
	build(L, M, id * 2 + 1);
	build(M, R, id * 2 + 2);
	merge(seg[id], seg[id * 2 + 1], seg[id * 2 + 2]);
}

Node query(int l, int r, int L = 0, int R = n, int id = 0) {
	if (l >= R || r <= L)
		return {0, 0, 0, 0};
	if (l <= L && R <= r)
		return seg[id];

	int M = (L + R) / 2;
	Node tmp;
	Node lc = query(l, r, L, M, id * 2 + 1), rc = query(l, r, M, R, id * 2 + 2);

	merge(tmp, lc, rc);
	return tmp;
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

	while (q--) {
		int l, r;
		cin >> l >> r;

		cout << query(l - 1, r).mx << '\n';
	}
}
