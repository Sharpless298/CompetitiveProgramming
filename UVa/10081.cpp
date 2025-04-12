#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed << setprecision(5);

	int k, n;
	while (cin >> k >> n) {
		vector<vector<double>> dp(n, vector<double>(k + 1));
		for (int i = 0; i <= k; i++)
			dp[0][i] = 1;

		for (int i = 1; i < n; i++) {
			for (int j = 0; j <= k; j++) {
				dp[i][j] = dp[i - 1][j];
				if (j != 0)
					dp[i][j] += dp[i - 1][j - 1];
				if (j != k)
					dp[i][j] += dp[i - 1][j + 1];
			}
		}

		double tot = 0;
		for (int i = 0; i <= k; i++)
			tot += dp[n - 1][i];

		cout << (tot / pow(k + 1, n)) * 100.0 << '\n';
	}
}
