#include <iostream>
using namespace std;

typedef long long int lli;

long long int dp[128][128];

lli C(int n, int m) {
	if (n == m || m == 0)
		return 1;
	if (dp[n][m])
		return dp[n][m];
	return dp[n][m] = C(n - 1, m) + C(n - 1, m - 1);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	while (cin >> n >> m && n)
		cout << n << " things taken " << m << " at a time is " << C(n, m) << " exactly.\n";
}
