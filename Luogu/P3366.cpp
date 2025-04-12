#include <algorithm>
#include <cstring>
#include <iostream>
#include <numeric>
using namespace std;

struct Edge {
	int u, v, w;
};

int parent[200005], sz[200005];
Edge edge[200005];

bool cmp(Edge &a, Edge &b) {
	return a.w < b.w;
}

void init(int n) {
	iota(parent, parent + n, 0);
	fill(sz, sz + n, 1);
}

int Find(int x) {
	return x == parent[x] ? x : parent[x] = Find(parent[x]);
}

bool Union(int a, int b) {
	a = Find(a), b = Find(b);

	if (a == b)
		return false;

	if (sz[a] > sz[b])
		swap(a, b);
	parent[a] = b;
	sz[b] += sz[a];
	return true;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, ans = 0;

	cin >> n >> m;
	init(n);
	for (int i = 0; i < m; i++) {
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
		edge[i].u--, edge[i].v--;
	}

	sort(edge, edge + m, cmp);
	int cnt = 0;
	for (int i = 0; i < m; i++)
		if (Union(edge[i].u, edge[i].v))
			cnt++, ans += edge[i].w;

	if (cnt == n - 1)
		cout << ans << '\n';
	else
		cout << "orz\n";
}
