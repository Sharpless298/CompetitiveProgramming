#include <iostream>
using namespace std;

typedef long long int lli;

lli dp[128];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	dp[0] = dp[1] = 1;
	for (int i = 2; i < 100; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	while (cin >> n)
		cout << dp[n] << '\n';
}
