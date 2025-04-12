#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> a, segtree;

void update(int k, int x, int id = 0, int L = 0, int R = n) {
	if (R - L == 1) {
		segtree[id] = x;
		return;
	}

	int M = (L + R) / 2;
	if (k < M)
		update(k, x, id * 2 + 1, L, M);
	else
		update(k, x, id * 2 + 2, M, R);

	segtree[id] = max(segtree[id * 2 + 1], segtree[id * 2 + 2]);
}

int query(int l, int r, int id = 0, int L = 0, int R = n) {
	if (l >= R || r <= L)
		return 0;
	if (l <= L && R <= r)
		return segtree[id];

	int M = (L + R) / 2;
	return max(query(l, r, id * 2 + 1, L, M), query(l, r, id * 2 + 2, M, R));
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector<int> v = a;
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for (int i = 0; i < n; i++)
		a[i] = (int)(lower_bound(v.begin(), v.end(), a[i]) - v.begin());

	n = (int)v.size();
	segtree.resize(4 * n);

	for (int i = 0; i < n; i++)
		update(a[i], query(0, a[i]) + 1);

	cout << segtree[0] << '\n';
}
