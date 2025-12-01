#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	const int shift = 20000;
	int ans = n;
	vector<vector<int>> dp(n, vector<int>(2 * shift + 1));
	for (int i = 0; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			dp[i][a[i] - a[j] + shift] += dp[j][a[i] - a[j] + shift] + 1;
			dp[i][a[i] - a[j] + shift] %= MOD;
			ans += dp[j][a[i] - a[j] + shift] + 1;
			ans %= MOD;
		}
	}
	cout << ans << '\n';
}
