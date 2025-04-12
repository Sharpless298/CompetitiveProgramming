#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;
	vector<vector<int>> a(n, vector<int>(3));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			cin >> a[i][j];

	vector<vector<int>> dp(n, vector<int>(3));
	for (int i = 0; i < 3; i++)
		dp[0][i] = a[0][i];
	for (int i = 1; i < n; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				if (j != k)
					dp[i][j] = max(dp[i][j], dp[i - 1][k] + a[i][j]);

	cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << '\n';
}
