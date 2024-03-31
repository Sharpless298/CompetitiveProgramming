#include <iostream>
using namespace std;

const int INF = 2e9;

int n, ans, dp[128], w[1024], v[1024];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> n) {
		fill(dp, dp+101, -INF);
		ans = dp[0] = 0;

		for(int i=0; i<n; i++)
			cin >> w[i] >> v[i];

		for(int i=0; i<n; i++) {
			for(int j=100; j>=w[i]; j--) {
				dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
				ans = max(ans, dp[j]);
			}
		}

		cout << ans << '\n';
	}
}
