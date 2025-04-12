#include <iostream>
#include <vector>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector<vector<bool>> dp(n, vector<bool>(k));
	dp[0][(a[0] % k + k) % k] = true;
	for (int i = 1; i < n; i++)
		for (int j = 0; j < k; j++)
			dp[i][j] = (dp[i - 1][((j - a[i]) % k + k) % k] || dp[i - 1][((j + a[i]) % k + k) % k]);

	if (dp[n - 1][0])
		cout << "Divisible\n";
	else
		cout << "Not divisible\n";
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--)
		solve();
}
