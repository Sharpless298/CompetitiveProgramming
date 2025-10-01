#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		int cur = 0;
		vector<int> dp(n + 1);
		map<int, int> last;
		last[0] = 0;
		for (int i = 1; i <= n; i++) {
			cur ^= a[i - 1];
			dp[i] = dp[i - 1];
			if (last.find(cur) != last.end()) {
				dp[i] = max(dp[i], dp[last[cur]] + 1);
			}
			last[cur] = i;
		}
		cout << n - dp[n] << '\n';
	}
}
