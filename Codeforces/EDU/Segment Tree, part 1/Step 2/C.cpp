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

int query(int x, int id = 0, int L = 0, int R = n) {
	if (R - L == 1)
		return L;

	int M = (L + R) / 2;
	if (seg[id * 2 + 1] >= x)
		return query(x, id * 2 + 1, L, M);
	else
		return query(x, id * 2 + 2, M, R);
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
			int x;
			cin >> x;
			if (seg[0] < x)
				cout << -1 << '\n';
			else
				cout << query(x) << '\n';
		}
	}
}
