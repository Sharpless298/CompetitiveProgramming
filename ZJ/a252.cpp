#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string a, b, c;

	cin >> a >> b >> c;
	vector<vector<vector<int>>> dp(a.size() + 1, vector<vector<int>>(b.size() + 1, vector<int>(c.size() + 1)));
	for (int i = 1; i <= (int)a.size(); i++) {
		for (int j = 1; j <= (int)b.size(); j++) {
			for (int k = 1; k <= (int)c.size(); k++) {
				if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1])
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				else
					dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
			}
		}
	}

	cout << dp[a.size()][b.size()][c.size()] << '\n';
}
