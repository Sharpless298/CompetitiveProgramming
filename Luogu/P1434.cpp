#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> G(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> G[i][j];
		}
	}

	int dx[] = {1, 0, -1, 0};
	int dy[] = {0, 1, 0, -1};
	vector<vector<int>> dp(n, vector<int>(m, 1));
	for (int c = 0; c < n * m / 2; c++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < 4; k++) {
					int ni = i + dx[k], nj = j + dy[k];
					if (0 <= ni && ni < n && 0 <= nj && nj < m && (G[i][j] > G[ni][nj])) {
						dp[i][j] = max(dp[i][j], dp[ni][nj] + 1);
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << '\n';
}
