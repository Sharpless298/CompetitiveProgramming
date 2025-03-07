#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int Case = 1; Case <= T; Case++) {
		string s;
		cin >> s;

		int len = (int)s.size();
		vector<vector<int>> dp(len, vector<int>(len));
		for (int i = len - 1; i >= 0; i--) {
			for (int j = i + 1; j < len; j++) {
				if (s[i] == s[j])
					dp[i][j] = dp[i + 1][j - 1];
				else
					dp[i][j] = min({dp[i + 1][j], dp[i][j - 1], dp[i + 1][j - 1]}) + 1;
			}
		}

		cout << "Case " << Case << ": " << dp[0][len - 1] << '\n';
	}
}
