#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, Case = 0;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;

		vector<int> dp(n);
		dp[0] = 0;
		for (int i = 1; i < n; i++)
			dp[i] = (dp[i - 1] + k) % (i + 1);

		cout << "Case " << ++Case << ": " << dp[n - 1] + 1 << '\n';
	}
}
