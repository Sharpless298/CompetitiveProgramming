#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

struct Edge {
	int u, v, w;
	bool operator<(Edge const &a) {
		return w < a.w;
	}
};

int cnt, ans;
int parent[10005], rk[10005];

Edge edges[1000005];

void init(int n) {
	cnt = ans = 0;
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	memset(rk, 0, sizeof(int) * n);
	memset(edges, 0, sizeof(Edge) * n);
}

int Find(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	a = Find(a), b = Find(b);

	if (rk[a] < rk[b])
		parent[a] = b;
	else if (rk[a] > rk[b])
		parent[b] = a;
	else
		parent[a] = b, rk[b]++;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;

	while (cin >> n >> m && n) {
		init(n);

		for (int i = 0; i < m; i++)
			cin >> edges[i].u >> edges[i].v >> edges[i].w;

		sort(edges, edges + m);
		for (int i = 0; i < m; i++) {
			if (Find(edges[i].u) != Find(edges[i].v)) {
				cnt++;
				Union(edges[i].u, edges[i].v);
				ans += edges[i].w;
			}
		}

		if (n != cnt + 1)
			cout << -1 << '\n';
		else
			cout << ans << '\n';
	}
}
