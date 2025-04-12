#include <iostream>
#include <queue>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		vector<int> deg(n);
		vector<vector<int>> G(n);
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			G[u].push_back(v);
			G[v].push_back(u);
			deg[u]++, deg[v]++;
		}

		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++)
			if (deg[i] <= 1)
				q.push({i, 0});

		int ans = n;
		for (int i = 0; i < k; i++) {
			if (ans == 0)
				break;
			while (!q.empty() && q.front().second == i) {
				int u = q.front().first;
				q.pop();
				deg[u]--, ans--;
				for (int v : G[u]) {
					deg[v]--;
					if (deg[v] == 1)
						q.push({v, i + 1});
				}
			}
		}

		cout << ans << '\n';
	}
}
