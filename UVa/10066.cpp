#include <iostream>
#include <vector>
using namespace std;

int n1, n2, Case;

void solve() {
	vector<int> a(n1 + 1), b(n2 + 1);
	for (int i = 1; i <= n1; i++)
		cin >> a[i];
	for (int i = 1; i <= n2; i++)
		cin >> b[i];

	vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= n2; j++) {
			if (a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << "Twin Towers #" << ++Case << '\n';
	cout << "Number of Tiles : " << dp[n1][n2] << '\n';
	cout << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> n1 >> n2 && n1)
		solve();
}
