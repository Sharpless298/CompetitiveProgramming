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
		int n;
		cin >> n;
		vector<int> r(n), in(n);
		vector<vector<int>> G(n);
		for (int i = 0; i < n; i++) {
			cin >> r[i];
			r[i]--;
			in[r[i]]++;
			G[r[i]].push_back(i);
		}

		queue<int> q;
		for (int i = 0; i < n; i++)
			if (in[i] == 0)
				q.push(i);

		vector<int> dp(n, 1);
		while (!q.empty()) {
			int u = q.front();
			q.pop();

			in[r[u]]--;
			dp[r[u]] += dp[u];
			if (in[r[u]] == 0)
				q.push(r[u]);
		}

		int ans = 2;
		for (int i = 0; i < n; i++) {
			if (in[i] != 0) {
				for (int u : G[i])
					if (in[u] == 0)
						ans = max(ans, dp[u] + 2);
			}
		}
		cout << ans << '\n';
	}
}
