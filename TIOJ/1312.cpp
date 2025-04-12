#include <iostream>
using namespace std;

int parent[10005];

int query(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = query(parent[x]);
}

void Union(int a, int b) {
	a = query(a), b = query(b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;

	while (cin >> n >> m) {
		for (int i = 1; i <= n; i++)
			parent[i] = i;

		for (int i = 0, a, b; i < m; i++)
			cin >> a >> b, Union(a, b);
		cin >> k;

		cout << query(k) << '\n';
	}
}
