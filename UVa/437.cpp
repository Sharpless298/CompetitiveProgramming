#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node {
	int x, y, z;
};

int Case;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	while (cin >> n && n) {
		vector<Node> a;
		for (int i = 0; i < n; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			a.push_back({x, y, z});
			a.push_back({x, z, y});
			a.push_back({y, z, x});
		}

		vector<int> deg(3 * n);
		vector<vector<int>> G(3 * n, vector<int>());
		for (int i = 0; i < 3 * n; i++) {
			for (int j = 0; j < 3 * n; j++) {
				if (i == j)
					continue;
				if ((a[i].x < a[j].x && a[i].y < a[j].y) || (a[i].x < a[j].y && a[i].y < a[j].x))
					G[i].push_back(j), deg[j]++;
			}
		}

		vector<int> dp(3 * n);
		stack<int> stk;
		for (int i = 0; i < 3 * n; i++)
			if (deg[i] == 0)
				stk.push(i), dp[i] = a[i].z;

		while (!stk.empty()) {
			int u = stk.top();
			stk.pop();

			for (int v : G[u]) {
				if (--deg[v] == 0)
					stk.push(v);
				dp[v] = max(dp[v], dp[u] + a[v].z);
			}
		}

		int ans = 0;
		for (int i = 0; i < 3 * n; i++)
			ans = max(ans, dp[i]);

		cout << "Case " << ++Case << ": maximum height = " << ans << '\n';
	}
}
