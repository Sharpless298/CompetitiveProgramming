#include <algorithm>
#include <iostream>
using namespace std;

typedef long long int lli;

struct Edge {
	int u, v, w;
	bool operator<(const Edge &a) {
		return w < a.w;
	}
};

int parent[200005], rk[200005];
lli ans;
Edge edges[200005];

void init(int n) {
	for (int i = 1; i <= n; i++)
		parent[i] = i, rk[i] = 1;
}

int Find(int x) {
	return x == parent[x] ? x : parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	if (rk[a] < rk[b])
		swap(a, b);
	parent[b] = a;
	if (rk[a] == rk[b])
		rk[a]++;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, cnt;

	cin >> n >> m;
	cnt = n - 1;
	init(n);
	for (int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		edges[i] = {a, b, c};
	}

	sort(edges, edges + m);

	for (int i = 0, a, b; cnt && i < m; i++) {
		a = Find(edges[i].u), b = Find(edges[i].v);

		if (a == b)
			continue;
		Union(a, b), cnt--;
		ans += edges[i].w;
	}

	cout << ans << '\n';
}
