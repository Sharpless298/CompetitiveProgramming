#include <iostream>
#include <utility>
#include <vector>
using namespace std;

bool vis[200005][2];
int parent[200005], ary[200005][2], ans[200005];
pair<int, int> p[400005];
vector<int> v[200005];

int Find(int x) {
	return x == parent[x] ? x : parent[x] = Find(parent[x]);
}

void Union(int a, int b, int t) {
	a = Find(a), b = Find(b);

	if (a == b)
		return;

	if (b == Find(1))
		swap(a, b);
	if (a == Find(1))
		for (int i : v[b])
			ans[i] = t;
	if (v[a].size() < v[b].size())
		swap(a, b);
	for (int i : v[b])
		v[a].push_back(i);
	parent[b] = a;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		parent[i] = i, v[i].push_back(i);

	for (int i = 1, x, y; i <= n; i++) {
		cin >> x >> y;
		ary[i][0] = x;
		ary[i][1] = y;
	}
	for (int i = 0, x, y; i < m; i++) {
		cin >> x >> y;
		p[i].first = x, p[i].second = y - 1;
		vis[x][y - 1] = true;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 2; j++)
			if (~ary[i][j] && !vis[i][j])
				Union(i, ary[i][j], -1);

	ans[1] = -1;
	for (int i = m - 1, k; i >= 0; i--) {
		k = ary[p[i].first][p[i].second];
		if (k == -1)
			continue;
		Union(k, p[i].first, i);
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i] << '\n';
}
