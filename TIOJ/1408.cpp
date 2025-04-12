#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int data, sz, lazy;
};

vector<Node> segtree(400000);

void push(int id) {
	if (!segtree[id].lazy)
		return;

	segtree[id].data += segtree[id].lazy * segtree[id].sz;
	segtree[id * 2 + 1].lazy += segtree[id].lazy;
	segtree[id * 2 + 2].lazy += segtree[id].lazy;
	segtree[id].lazy = 0;
}

void build(int id = 0, int L = 0, int R = 100000) {
	segtree[id] = {0, R - L, 0};
	if (R - L == 1)
		return;

	int M = (L + R) / 2;
	build(id * 2 + 1, L, M);
	build(id * 2 + 2, M, R);
}

void update(int l, int r, int x, int id = 0, int L = 0, int R = 100000) {
	if (l >= R || r <= L)
		return;
	if (l <= L && R <= r) {
		segtree[id].lazy += x;
		return;
	}

	int M = (L + R) / 2;
	update(l, r, x, id * 2 + 1, L, M);
	update(l, r, x, id * 2 + 2, M, R);
	segtree[id].data = segtree[id * 2 + 1].data + segtree[id * 2 + 1].lazy * segtree[id * 2 + 1].sz +
					   segtree[id * 2 + 2].data + segtree[id * 2 + 2].lazy * segtree[id * 2 + 2].sz;
}

int query(int l, int r, int id = 0, int L = 0, int R = 100000) {
	if (l >= R || r <= L)
		return 0;
	if (l <= L && R <= r)
		return segtree[id].data + segtree[id].lazy * segtree[id].sz;

	push(id);
	int M = (L + R) / 2;
	return query(l, r, id * 2 + 1, L, M) + query(l, r, id * 2 + 2, M, R);
}

struct seg {
	int l, r, c;
};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	while (cin >> n && n) {
		vector<seg> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i].l >> a[i].r >> a[i].c;

		build();

		sort(a.begin(), a.end(), [](seg &p, seg &q) { return p.r < q.r; });
		int ans = 0;
		vector<pair<int, int>> stk;
		for (int i = 0; i < n; i++) {
			a[i].c -= query(a[i].l, a[i].r);
			if (a[i].c <= 0)
				continue;

			int now = a[i].r;
			ans += a[i].c;
			while (!stk.empty() && now - stk.back().second <= a[i].c) {
				a[i].c -= now - stk.back().second;
				now = stk.back().first;
				update(stk.back().first, stk.back().second, -1);
				stk.pop_back();
			}
			update(now - a[i].c, a[i].r, 1);
			stk.push_back({now - a[i].c, a[i].r});
		}

		cout << ans << '\n';
	}
}
