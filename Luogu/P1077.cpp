#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e6 + 7;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector<int> dp(m + 1), pref(m + 1, 1);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			int t = j - min(a[i], j) - 1;
			if (t < 0)
				dp[j] = (dp[j] + pref[j - 1]) % MOD;
			else
				dp[j] = (dp[j] + pref[j - 1] - pref[t] + MOD) % MOD;
		}
		for (int j = 1; j <= m; j++)
			pref[j] = (pref[j - 1] + dp[j]) % MOD;
	}
	cout << dp[m] << '\n';
}
