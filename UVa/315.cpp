#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<int> dfn, low;

int timestamp = 1, ans;
void DFS(int u, int p) {
	int cnt = 0;
	dfn[u] = low[u] = timestamp++;

	bool f = false;
	for (int v : G[u]) {
		if (v == p)
			continue;
		if (!dfn[v]) {
			DFS(v, u), cnt++;
			if (dfn[u] <= low[v])
				f = true;
			low[u] = min(low[u], low[v]);
		}
		low[u] = min(low[u], dfn[v]);
	}
	if (u == p && cnt < 2)
		f = false;
	if (f)
		ans++;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	while (cin >> n && n) {
		G.assign(n, vector<int>());

		string s;
		while (getline(cin, s)) {
			if (s == "0")
				break;
			stringstream ss(s);
			int u;
			ss >> u;
			u--;
			int v;
			while (ss >> v) {
				v--;
				G[u].push_back(v);
				G[v].push_back(u);
			}
		}
		ans = 0;
		dfn.assign(n, 0), low.assign(n, 0);
		DFS(0, 0);

		cout << ans << '\n';
	}
}
