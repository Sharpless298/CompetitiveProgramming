#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int w[1024], in[1024], dp[1024];
vector<int> G[1024];
queue<int> q;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, n, v, ans;

	cin >> T;
	while (T--) {
		ans = 0;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < 1024; i++)
			G[i].clear();

		cin >> n;
		for (int i = 1, k; i <= n; i++) {
			cin >> w[i] >> k;
			while (k--)
				cin >> v, G[i].push_back(v), in[v]++;
		}

		for (int i = 1; i <= n; i++)
			if (in[i] == 0)
				q.push(i), dp[i] = w[i];

		while (!q.empty()) {
			v = q.front(), q.pop();

			for (int i : G[v]) {
				in[i]--;
				if (in[i] == 0)
					q.push(i);
				dp[i] = max(dp[i], dp[v] + w[i]);
				ans = max(ans, dp[i]);
			}
		}

		cout << ans << '\n';
	}
}
