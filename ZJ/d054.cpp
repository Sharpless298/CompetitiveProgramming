#include <iostream>
using namespace std;

typedef long long int lli;

int T, n;
lli dp[45];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	dp[0] = dp[1] = 1;
	dp[2] = 5;
	for (int i = 3; i <= 40; i++)
		dp[i] = dp[i - 3] * 2 + dp[i - 2] * 4 + dp[i - 1];

	cin >> T;
	while (T--) {
		cin >> n;

		cout << dp[n] << '\n';
	}
}
