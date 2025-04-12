#include <iostream>
using namespace std;

typedef long long int lli;

const int MOD = 1e9 + 9;

int T, n;
lli dp[105];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	dp[1] = 1;
	for (int i = 2; i <= 100; i++)
		dp[i] = (4 * dp[i - 1] - dp[i - 2] + MOD) % MOD;

	cin >> T;
	while (T--) {
		cin >> n;

		cout << dp[n] << '\n';
	}
}
