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

int cnt, n, m;
long long int ans;
int parent[100005], rk[100005];

Edge edges[200005];

void init() {
	cnt = ans = 0;
	for (int i = 0; i < 100005; i++)
		parent[i] = i;
	memset(rk, 0, sizeof(rk));
	memset(edges, 0, sizeof(edges));
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

	while (cin >> n >> m) {
		init();

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
