#include <iostream>
using namespace std;

int parent[200005], rk[200005], ans[200005];

void init(int n) {
	for (int i = 1; i <= n; i++)
		parent[i] = i, rk[i] = 1;
}

int Find(int x) {
	return x == parent[x] ? x : Find(parent[x]);
}

void Union(int a, int b) {
	a = Find(a), b = Find(b);

	if (a == b)
		return;

	if (rk[a] < rk[b])
		swap(a, b);
	parent[b] = a;
	ans[b] -= ans[a];
	if (rk[a] == rk[b])
		rk[a]++;
}

int query(int x) {
	return x == parent[x] ? ans[x] : ans[x] + query(parent[x]);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int x, y, n, m;
	string s;

	cin >> n >> m;

	init(n);

	while (m--) {
		cin >> s;

		if (s[0] == 'j')
			cin >> x >> y, Union(x, y);
		else if (s[0] == 'a')
			cin >> x >> y, ans[Find(x)] += y;
		else
			cin >> x, cout << query(x) << '\n';
	}
}
