#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<bool> vis;
vector<int> mp, mq;
bool DFS(int u) {
	vis[u] = true;
	for (int v : G[u]) {
		if (mq[v] == -1 || (!vis[mq[v]] && DFS(mq[v]))) {
			mp[u] = v;
			mq[v] = u;
			return true;
		}
	}
	return false;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int p, q, k;
		cin >> p >> q >> k;
		G.assign(p, vector<int>());
		for (int i = 0; i < k; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			G[u].push_back(v);
		}

		int ans = 0;
		vis.resize(p);
		mp.assign(p, -1), mq.assign(q, -1);
		for (int i = 0; i < p; i++) {
			fill(vis.begin(), vis.end(), false);
			if (DFS(i))
				ans++;
		}
		cout << ans << '\n';
	}
}
