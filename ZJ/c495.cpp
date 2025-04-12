#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

typedef long long int lli;

struct Edge {
	int u, v, w;
	bool operator<(const Edge &a) {
		return w < a.w;
	}
};

int N, M;
int parent[100005], rk[100005];
int ac[20][100005], mx[20][100005], depth[100005];
lli ans1, ans2;
queue<int> q;
vector<pair<int, int>> G[100005];
Edge edges[500005];

void init(int n) {
	for (int i = 1; i <= n; i++)
		parent[i] = i, rk[i] = 0;
}

int Find(int x) {
	return x == parent[x] ? x : parent[x] = Find(parent[x]);
}

bool Union(int a, int b) {
	a = Find(a), b = Find(b);

	if (a == b)
		return false;
	if (rk[a] < rk[b])
		parent[a] = b;
	if (rk[a] > rk[b])
		parent[b] = a;
	else
		parent[a] = b, rk[b]++;

	return true;
}

int query(int u, int v) {
	int res = 0;

	if (depth[u] < depth[v])
		swap(u, v);
	for (int i = 16; i >= 0; i--) {
		if (depth[ac[i][u]] >= depth[v]) {
			res = max(res, mx[i][u]);
			u = ac[i][u];
		}
	}
	if (u == v)
		return res;

	for (int i = 16; i >= 0; i--) {
		if (ac[i][u] != ac[i][v]) {
			res = max({res, mx[i][u], mx[i][v]});
			u = ac[i][u];
			v = ac[i][v];
		}
	}

	return max({res, mx[0][u], mx[0][v]});
}

void DFS(int u, int f) {
	depth[u] = depth[f] + 1;
	for (auto &v : G[u]) {
		if (v.first == f)
			continue;
		ac[0][v.first] = u;
		mx[0][v.first] = v.second;
		DFS(v.first, u);
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
		cin >> edges[i].u >> edges[i].v >> edges[i].w;

	init(N);
	sort(edges, edges + M);
	for (int i = 0; i < M; i++) {
		if (Union(edges[i].u, edges[i].v)) {
			G[edges[i].u].push_back(make_pair(edges[i].v, edges[i].w));
			G[edges[i].v].push_back(make_pair(edges[i].u, edges[i].w));
			ans1 += edges[i].w;
		} else
			q.push(i);
	}

	DFS(1, 0);
	for (int i = 1; i <= 16; i++) {
		for (int j = 1; j <= N; j++) {
			ac[i][j] = ac[i - 1][ac[i - 1][j]];
			mx[i][j] = max(mx[i - 1][j], mx[i - 1][ac[i - 1][j]]);
		}
	}

	ans2 = LONG_LONG_MAX;
	while (!q.empty()) {
		int i = q.front();
		q.pop();
		ans2 = min(ans2, ans1 + edges[i].w - query(edges[i].u, edges[i].v));
	}

	cout << ans1 << ' ' << ans2 << '\n';
}
