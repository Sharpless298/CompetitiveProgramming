#include <iostream>
using namespace std;

typedef unsigned long long int ulli;

int n;
ulli dp[64];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	dp[0] = 1;
	dp[1] = 3;
	for (int i = 2; i <= 50; i++)
		dp[i] = dp[i - 1] * 2 + dp[i - 2];

	while (cin >> n)
		cout << dp[n] << '\n';
}
