#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	while (cin >> n) {
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];

		vector<int> dp(n);
		dp[0] = max(0, a[0]);
		dp[1] = max(dp[0], a[1]);
		for (int i = 2; i < n; i++) {
			dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
		}

		cout << dp[n - 1] << '\n';
	}
}
