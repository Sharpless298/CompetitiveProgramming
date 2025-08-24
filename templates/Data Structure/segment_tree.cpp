#include <iostream>
#include <vector>
using namespace std;

struct Node {
	long long data, sz, lazy;
};

int n;
vector<int> a;
vector<Node> segtree;

void pull(int id) {
	segtree[id].data = segtree[id * 2 + 1].data + segtree[id * 2 + 1].sz * segtree[id * 2 + 1].lazy +
					   segtree[id * 2 + 2].data + segtree[id * 2 + 2].sz * segtree[id * 2 + 2].lazy;
}

void push(int id) {
	if (!segtree[id].lazy) {
		return;
	}

	segtree[id].data += segtree[id].sz * segtree[id].lazy;
	segtree[id * 2 + 1].lazy += segtree[id].lazy;
	segtree[id * 2 + 2].lazy += segtree[id].lazy;
	segtree[id].lazy = 0;
}

void build(int id = 0, int L = 0, int R = n) {
	segtree[id].sz = R - L;
	if (R - L == 1) {
		segtree[id].data = a[L];
		return;
	}

	int M = (L + R) / 2;
	build(id * 2 + 1, L, M);
	build(id * 2 + 2, M, R);
	pull(id);
}

void update(int l, int r, long long k, int id = 0, int L = 0, int R = n) {
	if (l >= R || r <= L) {
		return;
	}
	if (l <= L && R <= r) {
		segtree[id].lazy += k;
		return;
	}

	int M = (L + R) / 2;
	update(l, r, k, id * 2 + 1, L, M);
	update(l, r, k, id * 2 + 2, M, R);
	pull(id);
}

long long query(int l, int r, int id = 0, int L = 0, int R = n) {
	if (l >= R || r <= L) {
		return 0LL;
	}
	if (l <= L && R <= r) {
		return segtree[id].data + segtree[id].sz * segtree[id].lazy;
	}
	push(id);
	int M = (L + R) / 2;
	return query(l, r, id * 2 + 1, L, M) + query(l, r, id * 2 + 2, M, R);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	segtree.resize(4 * n);
	build();

	int q;
	cin >> q;
	while (q--) {
		int t, l, r;
		long long k;
		cin >> t >> l >> r;

		if (t == 1) {
			cin >> k;
			update(l - 1, r, k);
		} else {
			cout << query(l - 1, r) << '\n';
		}
	}
}
