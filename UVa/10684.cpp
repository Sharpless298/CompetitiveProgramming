#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	while (cin >> n && n) {
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector<int> dp(n);
		dp[0] = a[0];
		for (int i = 1; i < n; i++)
			dp[i] = max(0, dp[i - 1]) + a[i];

		int ans = 0;
		for (int i = 0; i < n; i++)
			ans = max(ans, dp[i]);

		if (ans == 0)
			cout << "Losing streak.\n";
		else
			cout << "The maximum winning streak is " << ans << ".\n";
	}
}
