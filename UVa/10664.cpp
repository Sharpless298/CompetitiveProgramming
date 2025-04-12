#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	cin.ignore();
	while (T--) {
		string s;
		stringstream ss;
		getline(cin, s);
		ss.str(s);

		int t, sum = 0;
		vector<int> w;
		while (ss >> t)
			sum += t, w.push_back(t);

		if (sum & 1) {
			cout << "NO\n";
			continue;
		}

		vector<vector<bool>> dp(w.size(), vector<bool>(sum + 1));
		dp[0][0] = dp[0][w[0]] = true;
		for (int i = 1; i < (int)w.size(); i++) {
			for (int j = 0; j <= sum; j++)
				dp[i][j] = dp[i - 1][j];
			for (int j = w[i]; j <= sum; j++)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]]);
		}

		cout << (dp[w.size() - 1][sum / 2] ? "YES\n" : "NO\n");
	}
}
