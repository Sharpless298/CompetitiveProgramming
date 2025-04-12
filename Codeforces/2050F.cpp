#include <bits/stdc++.h>
using namespace std;

vector<int> segtree, d;
void build(int id, int L, int R) {
	if (R - L == 1) {
		segtree[id] = d[L];
		return;
	}

	int M = (L + R) / 2;
	build(id * 2 + 1, L, M);
	build(id * 2 + 2, M, R);
	segtree[id] = __gcd(segtree[id * 2 + 1], segtree[id * 2 + 2]);
}

int query(int l, int r, int id, int L, int R) {
	if (l >= R || r <= L)
		return 0;
	if (l <= L && R <= r)
		return segtree[id];

	int M = (L + R) / 2;
	return __gcd(query(l, r, id * 2 + 1, L, M), query(l, r, id * 2 + 2, M, R));
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, q;
		cin >> n >> q;
		vector<int> a(n);
		for (int &i : a)
			cin >> i;

		d.assign(n, 0);
		for (int i = 0; i < n - 1; i++)
			d[i] = abs(a[i] - a[i + 1]);
		d[n - 1] = 0;

		segtree.assign(4 * n, 0);
		build(0, 0, n);
		while (q--) {
			int l, r;
			cin >> l >> r;
			cout << query(l - 1, r - 1, 0, 0, n) << ' ';
		}
		cout << '\n';
	}
}
