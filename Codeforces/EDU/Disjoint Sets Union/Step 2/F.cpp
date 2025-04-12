#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <numeric>
using namespace std;

struct Edge {
	int u, v, w;
	bool operator<(const Edge &a) {
		return w < a.w;
	}
};

int parent[1005], rk[1005];
Edge edges[10005];

int Find(int x) {
	return x == parent[x] ? x : parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	if (rk[a] < rk[b])
		swap(a, b);
	if (rk[a] == rk[b])
		rk[a]++;
	parent[b] = a;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, ans = INT_MAX, cnt;

	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> edges[i].u >> edges[i].v >> edges[i].w;

	sort(edges, edges + m);
	for (int i = 0; i < m; i++) {
		iota(parent, parent + 1005, 0);
		memset(rk, 0, sizeof(rk));

		cnt = 0;
		for (int j = i; j < m; j++) {
			int a = Find(edges[j].u), b = Find(edges[j].v);

			if (a == b)
				continue;
			Union(a, b);
			cnt++;

			if (cnt == n - 1) {
				ans = min(ans, edges[j].w - edges[i].w);
				break;
			}
		}
	}

	if (ans != INT_MAX)
		cout << "YES\n"
			 << ans << '\n';
	else
		cout << "NO\n";
}
