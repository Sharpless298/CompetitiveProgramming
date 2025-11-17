#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> power(9);
	power[0] = 1;
	for (int i = 0; i < 8; i++) {
		power[i + 1] = power[i] * 10;
	}

	string s;
	int n;
	cin >> s >> n;
	int m = (int)s.size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0x3f3f3f3f));
	dp[0][0] = 0;
	for (int i = 1; i <= m; i++) {
		int sum = 0;
		for (int j = i - 1; j >= 0; j--) {
			sum += (s[j] - '0') * power[i - 1 - j];
			if (sum > n) {
				break;
			}

			for (int k = sum; k <= n; k++) {
				if (dp[j][k - sum] != 0x3f3f3f3f) {
					dp[i][k] = min(dp[i][sum], dp[j][k - sum] + (j == 0 ? 0 : 1));
				}
			}
		}
	}

	cout << (dp[m][n] == 0x3f3f3f3f ? -1 : dp[m][n]) << '\n';
}
