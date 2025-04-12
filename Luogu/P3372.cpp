#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

struct Node {
	int sz;
	lli data;
	lli tag;
};

int n, m;
vector<lli> a;
vector<Node> seg;

void push(int id) {
	seg[id].data += seg[id].tag * seg[id].sz;
	seg[id * 2 + 1].tag += seg[id].tag;
	seg[id * 2 + 2].tag += seg[id].tag;
	seg[id].tag = 0;
}

void build(int L = 0, int R = n, int id = 0) {
	seg[id].sz = R - L;

	if (R - L == 1) {
		seg[id].data = a[L];
		return;
	}
	int M = (L + R) / 2;
	build(L, M, id * 2 + 1);
	build(M, R, id * 2 + 2);
	seg[id].data = seg[id * 2 + 1].data + seg[id * 2 + 2].data;
}

void update(int l, int r, lli k, int L = 0, int R = n, int id = 0) {
	if (l >= R || r <= L)
		return;

	if (l <= L && R <= r) {
		seg[id].tag += k;
		return;
	}

	int M = (L + R) / 2;
	update(l, r, k, L, M, id * 2 + 1);
	update(l, r, k, M, R, id * 2 + 2);
	seg[id].data = seg[id * 2 + 1].data + seg[id * 2 + 1].tag * seg[id * 2 + 1].sz + seg[id * 2 + 2].data +
				   seg[id * 2 + 2].tag * seg[id * 2 + 2].sz;
}

lli query(int l, int r, int L = 0, int R = n, int id = 0) {
	if (l >= R || r <= L)
		return 0;
	if (l <= L && R <= r)
		return seg[id].data + seg[id].tag * seg[id].sz;

	push(id);
	int M = (L + R) / 2;
	return query(l, r, L, M, id * 2 + 1) + query(l, r, M, R, id * 2 + 2);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	seg.resize(4 * n);
	build();

	while (m--) {
		int t, l, r;
		lli k;
		cin >> t;

		if (t == 1) {
			cin >> l >> r >> k;
			update(l - 1, r, k);
		} else {
			cin >> l >> r;
			cout << query(l - 1, r) << '\n';
		}
	}
}
