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
	seg[id] = seg[id * 2 + 1] + seg[id * 2 + 2];
}

void update(int k, int id = 0, int L = 0, int R = n) {
	if (k < L || k >= R)
		return;
	if (R - L == 1) {
		seg[id] = !seg[id];
		return;
	}

	int M = (L + R) / 2;
	update(k, id * 2 + 1, L, M);
	update(k, id * 2 + 2, M, R);
	seg[id] = seg[id * 2 + 1] + seg[id * 2 + 2];
}

int find(int k, int id = 0, int L = 0, int R = n) {
	if (R - L == 1)
		return L;

	int M = (L + R) / 2;
	if (k < seg[id * 2 + 1])
		return find(k, id * 2 + 1, L, M);
	else
		return find(k - seg[id * 2 + 1], id * 2 + 2, M, R);
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
		int t, k;
		cin >> t >> k;

		if (t == 1)
			update(k);
		else
			cout << find(k) << '\n';
	}
}
