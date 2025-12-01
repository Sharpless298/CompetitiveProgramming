#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int>> a(n, vector<int>(n));
	int x, y, v;
	while (cin >> x >> y >> v && x && y && v) {
		x--, y--;
		a[x][y] = v;
	}

	int dp[n + 1][n + 1][n + 1][n + 1];
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			for (int k = 0; k < n + 1; k++) {
				for (int l = 0; l < n + 1; l++) {
					dp[i][j][k][l] = 0;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				for (int l = 1; l <= n; l++) {
					dp[i][j][k][l] = max({dp[i - 1][j][k - 1][l], dp[i - 1][j][k][l - 1],
										  dp[i][j - 1][k - 1][l], dp[i][j - 1][k][l - 1]});
					dp[i][j][k][l] += a[i - 1][j - 1] + a[k - 1][l - 1];
					if (i == k && j == l) {
						dp[i][j][k][l] -= a[i - 1][j - 1];
					}
				}
			}
		}
	}
	cout << dp[n][n][n][n] << '\n';
}
