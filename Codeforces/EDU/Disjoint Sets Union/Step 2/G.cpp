#include <algorithm>
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

int n, k, ans, cnt;
int parent[1505], rk[1505];
Edge edges[400005];

int Find(int x) {
	return x == parent[x] ? x : parent[x] = Find(parent[x]);
}

bool Union(int a, int b) {
	a = Find(a), b = Find(b);

	if (a == b)
		return false;

	if (rk[a] < rk[b])
		swap(a, b);
	if (rk[a] == rk[b])
		rk[a]++;
	parent[b] = a;
	return true;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	iota(parent, parent + 1505, 0);
	memset(rk, 0, sizeof(rk));

	cin >> n >> k;
	for (int i = 0; i < k; i++)
		cin >> edges[i].u >> edges[i].v >> edges[i].w;

	sort(edges, edges + k);

	cnt = n - 1;
	for (int i = 0; cnt && i < k; i++) {
		if (Union(edges[i].u, edges[i].v)) {
			cnt--;
			ans = edges[i].w;
		}
	}

	cout << ans << '\n';
}
