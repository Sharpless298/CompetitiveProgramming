#include <algorithm>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

typedef long long int lli;

struct Edge {
	int u, v, w, id;

	bool operator<(const Edge &a) {
		return w > a.w;
	}
};

bool f[100005];
int n, m, cnt;
int parent[50005], rk[50005];
lli s;
Edge edges[100005];
vector<int> ans;

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

	iota(parent, parent + 50005, 0);
	memset(rk, 0, sizeof(rk));

	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
		edges[i].id = i + 1;
	}

	sort(edges, edges + m);

	cnt = n - 1;
	for (int i = 0, a, b; cnt && i < m; i++) {
		a = Find(edges[i].u), b = Find(edges[i].v);

		if (a == b)
			continue;

		Union(a, b);
		f[i] = true;
	}

	for (int i = m - 1; i >= 0; i--)
		if (!f[i] && s >= edges[i].w)
			s -= edges[i].w, ans.push_back(edges[i].id);

	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < (int)ans.size(); i++) {
		if (i)
			cout << ' ';
		cout << ans[i];
	}
}
