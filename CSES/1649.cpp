#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> a, segtree;

void build(int id = 0, int L = 0, int R = n) {
	if (R - L == 1) {
		segtree[id] = a[L];
		return;
	}

	int M = (L + R) / 2;
	build(id * 2 + 1, L, M);
	build(id * 2 + 2, M, R);
	segtree[id] = min(segtree[id * 2 + 1], segtree[id * 2 + 2]);
}

void update(int k, int x, int id = 0, int L = 0, int R = n) {
	if (R - L == 1) {
		segtree[id] = x;
		return;
	}

	int M = (L + R) / 2;
	if (k < M)
		update(k, x, id * 2 + 1, L, M);
	else
		update(k, x, id * 2 + 2, M, R);
	segtree[id] = min(segtree[id * 2 + 1], segtree[id * 2 + 2]);
}

long long query(int l, int r, int id = 0, int L = 0, int R = n) {
	if (l >= R || r <= L)
		return 0x3f3f3f3f;
	if (l <= L && R <= r)
		return segtree[id];

	int M = (L + R) / 2;
	return min(query(l, r, id * 2 + 1, L, M), query(l, r, id * 2 + 2, M, R));
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> n >> q;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	segtree.resize(4 * n);
	build();

	while (q--) {
		int t;
		cin >> t;

		if (t == 1) {
			int k, u;
			cin >> k >> u;
			update(k - 1, u);
		} else {
			int l, r;
			cin >> l >> r;
			cout << query(l - 1, r) << '\n';
		}
	}
}
