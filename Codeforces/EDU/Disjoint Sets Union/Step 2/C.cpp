#include <iostream>
#include <numeric>
using namespace std;

int parent[200005], rk[200005], nxt[200005];

void init(int n) {
	for (int i = 1; i <= n; i++)
		parent[i] = nxt[i] = i, rk[i] = 1;
}

int Find(int x) {
	return x == parent[x] ? x : parent[x] = Find(parent[x]);
}

int f(int x) {
	return x == nxt[x] ? x : nxt[x] = f(nxt[x]);
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

	int n, m, k, a, b;

	cin >> n >> m;

	init(n);

	while (m--) {
		cin >> k >> a >> b;

		if (k == 1)
			Union(a, b);
		else if (k == 2) {
			for (int i = nxt[a]; i < b; i = nxt[i]) {
				nxt[i] = f(i + 1);
				Union(i, b);
			}
		} else {
			if (Find(a) == Find(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}
