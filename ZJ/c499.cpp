#include <iostream>
using namespace std;

int T, dp[1024][1024];
string a, b, s, t;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	getline(cin, a);
	getline(cin, b);
	cin >> T;

	s = "0" + a, t = "0" + b;

	for (int i = 1; i < (int)s.size(); i++) {
		for (int j = 1; j < (int)t.size(); j++) {
			if (s[i] == t[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	if (dp[(int)s.size() - 1][(int)t.size() - 1] >= T)
		cout << "kwa nini unaendesha\n";
	else
		cout << "sitini na tisa\n";
}
