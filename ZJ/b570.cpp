#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool f[1000005];
int n, m, q, k, cnt;
int parent[1000005], rk[1000005];
pair<int, int> p[1000005];
vector<int> E, ans;

int Find(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	a = Find(a), b = Find(b);

	if (a == b)
		return;
	if (rk[a] < rk[b])
		parent[a] = b;
	else if (rk[b] > rk[a])
		parent[b] = a;
	else
		parent[a] = b, rk[b]++;
	cnt--;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> p[i].first >> p[i].second;
	cin >> q;
	while (q--) {
		cin >> k;
		f[k] = true;
		E.push_back(k);
	}
	reverse(E.begin(), E.end());

	cnt = n;
	for (int i = 1; i <= n; i++)
		parent[i] = i, rk[i] = 1;

	for (int i = 1; i <= m; i++)
		if (!f[i])
			Union(p[i].first, p[i].second);

	for (int i : E) {
		ans.push_back(cnt);
		Union(p[i].first, p[i].second);
	}
	reverse(ans.begin(), ans.end());

	for (int i : ans)
		cout << i << '\n';
}
