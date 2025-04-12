#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long int lli;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> G(n, vector<int>(m));
	vector<vector<lli>> dp(n, vector<lli>(m));
	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			G[i][j] = c - '0';
			if (G[i][j] == 9)
				dp[i][j] = 1;
			else
				pq.push({G[i][j], i * m + j});
		}
	}

	while (!pq.empty()) {
		auto [a, b] = pq.top();
		pq.pop();

		int y = b / m, x = b % m;
		for (int i = 0; i < 4; i++) {
			int ty = y + dy[i];
			int tx = x + dx[i];

			if (ty >= 0 && ty < n && tx >= 0 && tx < m && G[ty][tx] == a + 1) {
				dp[y][x] += dp[ty][tx];
			}
		}
	}

	lli ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (G[i][j] == 0)
				ans += dp[i][j];

	cout << ans << '\n';
}
