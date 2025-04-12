#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

struct Edge {
	int u, v, c, id;
};

vector<int> parent(500000), sz(500000);

void init() {
	iota(parent.begin(), parent.end(), 0);
	fill(sz.begin(), sz.end(), 1);
}

int Find(int x) {
	return x == parent[x] ? x : parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	a = Find(a), b = Find(b);

	if (a == b)
		return;

	if (sz[a] > sz[b])
		swap(a, b);
	parent[a] = b;
	sz[b] += sz[a];
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<Edge> E(m);
	for (int i = 0; i < m; i++) {
		cin >> E[i].u >> E[i].v >> E[i].c;
		E[i].id = i;
	}

	init();
	sort(E.begin(), E.end(), [](Edge &a, Edge &b) { return a.c < b.c; });
	int cnt = 0;
	long long ans1 = 0;
	vector<int> ans2;
	for (int i = 0; i < m; i++) {
		if (cnt == n - 1)
			break;

		if (Find(E[i].u) != Find(E[i].v)) {
			Union(E[i].u, E[i].v);
			ans1 += E[i].c;
			ans2.push_back(E[i].id);
			cnt++;
		}
	}

	cout << ans1 << '\n';
	for (int i : ans2)
		cout << i << ' ';
	cout << '\n';
}
