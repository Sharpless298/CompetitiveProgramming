#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

struct Node {
	lli data;
	lli tag;
};

int n, q;
vector<int> a;
vector<Node> seg;

void push(int id) {
	seg[id].data += seg[id].tag;
	seg[id * 2 + 1].tag += seg[id].tag;
	seg[id * 2 + 2].tag += seg[id].tag;
	seg[id].tag = 0;
}

void build(int L = 0, int R = n, int id = 0) {
	if (R - L == 1) {
		seg[id].data = a[L];
		return;
	}

	int M = (L + R) / 2;
	build(L, M, id * 2 + 1);
	build(M, R, id * 2 + 2);
	seg[id].data = max(seg[id * 2 + 1].data, seg[id * 2 + 2].data);
}

void update(int l, int r, int x, int L = 0, int R = n, int id = 0) {
	if (l >= R || r <= L)
		return;
	if (l <= L && R <= r) {
		seg[id].tag += x;
		return;
	}

	int M = (L + R) / 2;
	update(l, r, x, L, M, id * 2 + 1);
	update(l, r, x, M, R, id * 2 + 2);

	seg[id].data = max(seg[id * 2 + 1].data + seg[id * 2 + 1].tag, seg[id * 2 + 2].data + seg[id * 2 + 2].tag);
}

lli query(int l, int r, int L = 0, int R = n, int id = 0) {
	if (l >= R || r <= L)
		return 0;
	if (l <= L && R <= r)
		return seg[id].data + seg[id].tag;

	push(id);
	int M = (L + R) / 2;
	return max(query(l, r, L, M, id * 2 + 1), query(l, r, M, R, id * 2 + 2));
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
		int t, l, r, x;
		cin >> t >> l >> r;

		if (t == 1) {
			cin >> x;
			update(l - 1, r, x);
		} else
			cout << query(l - 1, r) << '\n';
	}
}
