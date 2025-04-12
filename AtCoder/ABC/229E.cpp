#include <algorithm>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

vector<int> parent, sz;

void init(int n) {
	parent.resize(n);
	sz.resize(n);
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

vector<vector<int>> G;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	G.resize(n);
	init(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		u--, v--;
		G[u].push_back(v);
	}

	int cnt = 0;
	vector<int> ans = {0};
	for (int i = n - 1; i >= 1; i--) {
		cnt++;

		for (int j : G[i]) {
			if (Find(i) != Find(j)) {
				cnt--;
				Union(i, j);
			}
		}

		ans.push_back(cnt);
	}

	reverse(ans.begin(), ans.end());
	for (int i : ans)
		cout << i << '\n';
}
