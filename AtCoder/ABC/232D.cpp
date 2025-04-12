#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w;
	cin >> h >> w;
	vector<vector<char>> G(h, vector<char>(w));
	for (auto &i : G)
		for (auto &j : i)
			cin >> j;

	vector<vector<int>> dp(h + 1, vector<int>(w + 1));
	for (int i = h - 1; i >= 0; i--) {
		for (int j = w - 1; j >= 0; j--) {
			if (G[i][j] == '#')
				continue;

			dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]) + 1;
		}
	}

	cout << dp[0][0] << '\n';
}
