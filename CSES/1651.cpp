#include <iostream>
#include <vector>
using namespace std;

struct Node {
	long long data;
	int sz;
	long long lazy;
};

int n;
vector<int> a;
vector<Node> segtree;

void push(int id) {
	segtree[id].data += segtree[id].sz * segtree[id].lazy;
	segtree[id * 2 + 1].lazy += segtree[id].lazy;
	segtree[id * 2 + 2].lazy += segtree[id].lazy;
	segtree[id].lazy = 0;
}

void pull(int id) {
	segtree[id].data = segtree[id * 2 + 1].data + segtree[id * 2 + 1].sz * segtree[id * 2 + 1].lazy +
					   segtree[id * 2 + 2].data + segtree[id * 2 + 2].sz * segtree[id * 2 + 2].lazy;
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

void update(int l, int r, int x, int id = 0, int L = 0, int R = n) {
	if (l >= R || r <= L)
		return;
	if (l <= L && R <= r) {
		segtree[id].lazy += x;
		return;
	}

	int M = (L + R) / 2;
	update(l, r, x, id * 2 + 1, L, M);
	update(l, r, x, id * 2 + 2, M, R);
	pull(id);
}

long long query(int k, int id = 0, int L = 0, int R = n) {
	if (R - L == 1)
		return segtree[id].data + segtree[id].sz * segtree[id].lazy;

	push(id);

	int M = (L + R) / 2;
	if (k < M)
		return query(k, id * 2 + 1, L, M);
	else
		return query(k, id * 2 + 2, M, R);
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
			int l, r, u;
			cin >> l >> r >> u;
			update(l - 1, r, u);
		} else {
			int k;
			cin >> k;
			cout << query(k - 1) << '\n';
		}
	}
}
