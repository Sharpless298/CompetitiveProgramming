#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

int n, m;
vector<int> a;
vector<lli> seg;

void build(int id = 0, int L = 0, int R = n) {
	if (R - L == 1) {
		seg[id] = a[L];
		return;
	}
	int M = (L + R) / 2;
	build(id * 2 + 1, L, M);
	build(id * 2 + 2, M, R);
	seg[id] = min(seg[id * 2 + 1], seg[id * 2 + 2]);
}

void update(int x, int v, int id = 0, int L = 0, int R = n) {
	if (R - L == 1) {
		seg[id] = v;
		return;
	}

	int M = (L + R) / 2;
	if (x < M)
		update(x, v, id * 2 + 1, L, M);
	else
		update(x, v, id * 2 + 2, M, R);
	seg[id] = min(seg[id * 2 + 1], seg[id * 2 + 2]);
}

lli query(int l, int r, int id = 0, int L = 0, int R = n) {
	if (l >= R || r <= L)
		return 2000000000;
	if (l <= L && R <= r)
		return seg[id];

	int M = (L + R) / 2;
	return min(query(l, r, id * 2 + 1, L, M), query(l, r, id * 2 + 2, M, R));
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
			cout << query(l, r) << '\n';
		}
	}
}
