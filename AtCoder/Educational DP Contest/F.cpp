#include <iostream>
#include <vector>
using namespace std;

string f(string &a, string &b) {
	return (a.size() > b.size() ? a : b);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s, t;

	cin >> s >> t;
	vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1));
	for (int i = 1; i <= (int)s.size(); i++) {
		for (int j = 1; j <= (int)t.size(); j++) {
			if (s[i - 1] == t[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	int i = (int)s.size(), j = (int)t.size();
	string ans;
	while (i && j) {
		if (s[i - 1] == t[j - 1]) {
			ans = s[i - 1] + ans;
			i--, j--;
			continue;
		}

		if (dp[i - 1][j] > dp[i][j - 1])
			i--;
		else
			j--;
	}

	cout << ans << '\n';
}
