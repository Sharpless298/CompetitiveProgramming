#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

struct Edge {
	int u, v;
};

int parent[500005], rk[500005];
vector<pair<int, Edge>> v;
vector<string> ans;

void init(int n) {
	for (int i = 1; i <= n; i++)
		parent[i] = i, rk[i] = 1;
}

int Find(int x) {
	return x == parent[x] ? x : parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	a = Find(a), b = Find(b);

	if (a == b)
		return;

	if (rk[a] < rk[b])
		swap(a, b);
	parent[b] = a;
	if (rk[a] == rk[b])
		rk[a]++;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	string s;

	cin >> n >> m >> k, init(n);
	for (int i = 0, a; i < 2 * m; i++)
		cin >> a;

	while (k--) {
		int a, b;

		cin >> s >> a >> b;
		if (s[0] == 'a')
			v.push_back({0, {a, b}});
		else
			v.push_back({1, {a, b}});
	}

	reverse(v.begin(), v.end());
	for (auto &i : v) {
		if (i.first)
			Union(i.second.u, i.second.v);
		else {
			if (Find(i.second.u) == Find(i.second.v))
				ans.push_back("YES\n");
			else
				ans.push_back("NO\n");
		}
	}
	reverse(ans.begin(), ans.end());

	for (auto &i : ans)
		cout << i;
}
