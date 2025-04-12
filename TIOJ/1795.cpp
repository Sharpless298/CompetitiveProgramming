#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Edge {
	int u, v, w;
	bool operator<(Edge a) {
		return w < a.w;
	}
};

int n, m, k, cnt, MIN, MAX;
int parent[100005], rk[100005];
vector<Edge> edges;

void init() {
	cnt = n - 1;
	for (int i = 1; i <= n; i++)
		parent[i] = i, rk[i] = 1;
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

	cin >> n >> m >> k;
	for (int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		edges.push_back({a, b, c});
	}

	init();
	sort(edges.begin(), edges.end());
	for (int i = 0; cnt; i++) {
		if (Find(edges[i].u) != Find(edges[i].v)) {
			Union(edges[i].u, edges[i].v);
			MIN += edges[i].w;
			cnt--;
		}
	}

	init();
	reverse(edges.begin(), edges.end());
	for (int i = 0; cnt; i++) {
		if (Find(edges[i].u) != Find(edges[i].v)) {
			Union(edges[i].u, edges[i].v);
			MAX += edges[i].w;
			cnt--;
		}
	}

	if (MIN <= k && k <= MAX)
		cout << "TAK\n";
	else
		cout << "NIE\n";
}
