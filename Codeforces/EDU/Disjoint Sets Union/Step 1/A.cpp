#include <iostream>
using namespace std;

int parent[100005], rk[100005];

void init(int n) {
	for (int i = 1; i <= n; i++)
		parent[i] = i, rk[i] = 1;
}

int Find(int x) {
	return x == parent[x] ? x : parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	a = Find(a), b = Find(b);

	if (a == b)
		return;

	if (rk[a] < rk[b])
		swap(a, b);
	parent[b] = a;
	if (rk[a] == rk[b])
		rk[a]++;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, u, v;
	string s;

	cin >> n >> m;

	init(n);

	while (m--) {
		cin >> s >> u >> v;

		if (s == "union")
			Union(u, v);
		else {
			u = Find(u), v = Find(v);
			if (u == v)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}
