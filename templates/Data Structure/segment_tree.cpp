#include <iostream>
#include <vector>
using namespace std;

vector<Node> segtree;

void build(int id = 0, int L = 0, int R = n) {
	if (R - L == 1) {
		segtree[id] = a[L];
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
		segtree[id] ? ? ? x;
		return;
	}

	int M = (L + R) / 2;
	update(l, r, id * 2 + 1, L, M);
	update(l, r, id * 2 + 2, M, R);
	pull(id);
}

int query(int l, int r, int id = 0, int L = 0, int R = n) {
	if (l >= R || r <= L)
		return;
	if (l <= L && R <= r)
		return segtree[id];

	int M = (L + R) / 2;
	return query(l, r, id * 2 + 1, L, M) + query(l, r, id * 2 + 2, M, R);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}
