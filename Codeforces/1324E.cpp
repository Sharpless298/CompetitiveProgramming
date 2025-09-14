#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, h, l, r;
	cin >> n >> h >> l >> r;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, -0x3f3f3f3f));
	dp[0][0] = 0;
	for (int i = 0, s = 0; i < n; i++) {
		s += a[i];
		for (int j = 0; j <= i; j++) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + (l <= ((s - j) % h) && ((s - j) % h) <= r));
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + (l <= ((s - j - 1) % h) && ((s - j - 1) % h) <= r));
		}
	}

	cout << *max_element(dp[n].begin(), dp[n].end()) << '\n';
}
