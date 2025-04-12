#include <iostream>
#include <vector>
using namespace std;

int dp[128][128][128];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<vector<int>> a(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];

	vector<vector<int>> pref(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			pref[i][j] = pref[i][j - 1] + a[i][j];

	int ans = -128;
	for (int j = 1; j <= n - 1; j++)
		for (int k = j + 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				dp[i][j][k] = max(0, dp[i - 1][j][k]) + pref[i][k] - pref[i][j - 1], ans = max(ans, dp[i][j][k]);

	cout << ans << '\n';
}
