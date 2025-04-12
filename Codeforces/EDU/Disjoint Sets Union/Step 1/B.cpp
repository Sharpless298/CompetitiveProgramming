#include <iostream>
using namespace std;

int parent[300005], mx[300005], mn[300005], sz[300005];

void init(int n) {
	for (int i = 1; i <= n; i++)
		parent[i] = mx[i] = mn[i] = i, sz[i] = 1;
}

int Find(int x) {
	return x == parent[x] ? x : parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	a = Find(a), b = Find(b);

	if (a == b)
		return;

	if (sz[a] > sz[b])
		swap(a, b);
	parent[a] = b;
	sz[b] += sz[a];
	mx[b] = max(mx[a], mx[b]);
	mn[b] = min(mn[a], mn[b]);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, u, v;
	string s;

	cin >> n >> m;
	init(n);
	while (m--) {
		cin >> s;
		if (s == "union")
			cin >> u >> v, Union(u, v);
		else {
			cin >> u;

			u = Find(u);
			cout << mn[u] << ' ' << mx[u] << ' ' << sz[u] << '\n';
		}
	}
}
