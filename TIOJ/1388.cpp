#include <cstring>
#include <iostream>
using namespace std;

typedef long long int lli;

int n;
lli dp[105][105];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> n) {
		memset(dp, 0, sizeof(dp));

		for (int i = 0; i < n; i++)
			cin >> dp[i][i];

		for (int i = 1; i < n; i++) {
			for (int l = 0, r = l + i; r < n; l++, r++) {
				for (int k = l; k < r; k++) {
					if ((i + 1) & 1)
						dp[l][r] = max(dp[l][r], dp[l][k] * dp[k + 1][r]);
					else
						dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r]);
				}
			}
		}

		cout << dp[0][n - 1] << '\n';
	}
}
