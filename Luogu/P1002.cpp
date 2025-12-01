#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	vector<vector<bool>> f(21, vector<bool>(21));
	f[c][d] = true;
	int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
	int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
	for (int i = 0; i < 8; i++) {
		int nx = c + dx[i];
		int ny = d + dy[i];
		if (0 <= nx && nx <= 20 && 0 <= ny && ny <= 20) {
			f[nx][ny] = true;
		}
	}

	vector<vector<long long>> dp(21, vector<long long>(21));
	dp[0][0] = 1;
	for (int i = 0; i <= 20; i++) {
		for (int j = 0; j <= 20; j++) {
			if (f[i][j]) {
				continue;
			}
			if (i - 1 >= 0) {
				dp[i][j] += dp[i - 1][j];
			}
			if (j - 1 >= 0) {
				dp[i][j] += dp[i][j - 1];
			}
		}
	}

	cout << dp[a][b] << '\n';
}
