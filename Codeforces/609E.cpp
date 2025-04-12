#include <algorithm>
#include <cstring>
#include <iostream>
#include <numeric>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

typedef long long int lli;

struct Edge {
	int u, v, w, id;
	bool operator<(const Edge &a) {
		return w < a.w;
	}
};

bool used[200005];
int N, M;
int parent[200005], rk[200005];
int ac[200005][20], mx[200005][20], depth[200005];
lli sum, ans[200005];
Edge edges[200005];
vector<pair<int, int>> G[200005];

void init() {
	iota(parent, parent + 200005, 0);
	memset(rk, 0, sizeof(rk));
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

void DFS(int u, int f) {
	depth[u] = depth[f] + 1;
	for (auto &v : G[u]) {
		if (v.first == f)
			continue;
		ac[v.first][0] = u;
		mx[v.first][0] = v.second;
		for (int i = 1; i <= 17; i++) {
			ac[v.first][i] = ac[ac[v.first][i - 1]][i - 1];
			mx[v.first][i] = max(mx[v.first][i - 1], mx[ac[v.first][i - 1]][i - 1]);
		}
		DFS(v.first, u);
	}
}

int query(int u, int v) {
	int res = 0;

	if (depth[u] < depth[v])
		swap(u, v);
	for (int i = 17; i >= 0; i--) {
		if (depth[ac[u][i]] >= depth[v]) {
			res = max(res, mx[u][i]);
			u = ac[u][i];
		}
	}
	if (u == v)
		return res;

	for (int i = 17; i >= 0; i--) {
		if (ac[u][i] != ac[v][i]) {
			res = max({res, mx[u][i], mx[v][i]});
			u = ac[u][i];
			v = ac[v][i];
		}
	}

	return max({res, mx[u][0], mx[v][0]});
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
		edges[i].id = i;
	}

	init();
	sort(edges, edges + M);
	for (int i = 0; i < M; i++) {
		if (Union(edges[i].u, edges[i].v)) {
			G[edges[i].u].push_back(make_pair(edges[i].v, edges[i].w));
			G[edges[i].v].push_back(make_pair(edges[i].u, edges[i].w));
			sum += edges[i].w, used[i] = true;
		}
	}

	ac[1][0] = 1;
	DFS(1, 0);

	for (int i = 0; i < M; i++) {
		if (used[i])
			ans[edges[i].id] = sum;
		else
			ans[edges[i].id] = sum - query(edges[i].u, edges[i].v) + edges[i].w;
	}

	for (int i = 0; i < M; i++)
		cout << ans[i] << '\n';
}
