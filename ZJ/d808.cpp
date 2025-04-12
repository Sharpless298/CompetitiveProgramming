#include <iostream>
using namespace std;

int ans1, ans2;
int parent[1000005], sz[1000005];

void init(int n) {
	for (int i = 1; i <= n; i++)
		parent[i] = i, sz[i] = 1;
	ans1 = n, ans2 = -1;
}

int Find(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	a = Find(a), b = Find(b);

	if (a == b)
		return;

	if (sz[a] > sz[b])
		swap(a, b);
	parent[a] = b;
	sz[b] += sz[a];
	ans1--, ans2 = max(ans2, sz[b]);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	while (cin >> n) {
		init(n);

		for (int i = 1, k; i <= n; i++)
			cin >> k, Union(i, k);

		cout << ans1 << ' ' << ans2 << '\n';
	}
}
