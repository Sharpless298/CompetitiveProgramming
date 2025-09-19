#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int v[] = {0, 1, 5, 10, 25, 50};
	vector<int> dp(7490);
	dp[0] = 1;
	for (int i = 1; i <= 5; i++) {
		for (int j = v[i]; j < 7490; j++) {
			dp[j] += dp[j - v[i]];
		}
	}

	int n;
	while (cin >> n) {
		cout << dp[n] << '\n';
	}
}
