#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> a, seg;

void build(int id = 0, int L = 0, int R = n) {
	if (R - L == 1) {
		seg[id] = a[L];
		return;
	}

	int M = (L + R) / 2;
	build(id * 2 + 1, L, M);
	build(id * 2 + 2, M, R);
	seg[id] = max(seg[id * 2 + 1], seg[id * 2 + 2]);
}

void update(int x, int v, int id = 0, int L = 0, int R = n) {
	if (x < L || x >= R)
		return;
	if (R - L == 1) {
		seg[id] = v;
		return;
	}

	int M = (L + R) / 2;
	update(x, v, id * 2 + 1, L, M);
	update(x, v, id * 2 + 2, M, R);
	seg[id] = max(seg[id * 2 + 1], seg[id * 2 + 2]);
}

int query(int l, int x, int id = 0, int L = 0, int R = n) {
	if (R - L == 1) {
		if (L >= l && seg[id] >= x)
			return L;
		return -1;
	}

	int M = (L + R) / 2;

	int res = -1;

	if (M > l && seg[id * 2 + 1] >= x)
		res = query(l, x, id * 2 + 1, L, M);
	if (res == -1)
		res = query(l, x, id * 2 + 2, M, R);
	return res;
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
		int t;
		cin >> t;

		if (t == 1) {
			int i, v;
			cin >> i >> v;
			update(i, v);
		} else {
			int l, x;
			cin >> x >> l;
			cout << query(l, x) << '\n';
			;
		}
	}
}
