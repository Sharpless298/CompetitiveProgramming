#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int mn;
	int cnt;
};

int n, m;
vector<int> a;
vector<Node> seg;

void pull(int id) {
	if (seg[id * 2 + 1].mn < seg[id * 2 + 2].mn)
		seg[id] = seg[id * 2 + 1];
	else if (seg[id * 2 + 1].mn > seg[id * 2 + 2].mn)
		seg[id] = seg[id * 2 + 2];
	else
		seg[id].mn = seg[id * 2 + 1].mn, seg[id].cnt = seg[id * 2 + 1].cnt + seg[id * 2 + 2].cnt;
}

void build(int id = 0, int L = 0, int R = n) {
	if (R - L == 1) {
		seg[id].mn = a[L];
		seg[id].cnt = 1;
		return;
	}
	int M = (L + R) / 2;
	build(id * 2 + 1, L, M);
	build(id * 2 + 2, M, R);
	pull(id);
}

void update(int x, int v, int id = 0, int L = 0, int R = n) {
	if (R - L == 1) {
		seg[id].mn = v;
		return;
	}

	int M = (L + R) / 2;
	if (x < M)
		update(x, v, id * 2 + 1, L, M);
	else
		update(x, v, id * 2 + 1, M, R);
	pull(id);
}

Node query(int l, int r, int id = 0, int L = 0, int R = n) {
	if (l >= R || r <= L)
		return {2000000000, 1};
	if (l <= L && R <= r)
		return seg[id];

	int M = (L + R) / 2;
	Node x = query(l, r, id * 2 + 1, L, M), y = query(l, r, id * 2 + 2, M, R);

	if (x.mn < y.mn)
		return x;
	else if (x.mn > y.mn)
		return y;
	else
		return {x.mn, x.cnt + y.cnt};
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
		int t, i, v, l, r;
		cin >> t;

		if (t == 1) {
			cin >> i >> v;
			update(i, v);
		} else {
			cin >> l >> r;
			Node ans = query(l, r);
			cout << ans.mn << ' ' << ans.cnt << '\n';
		}
	}
}
