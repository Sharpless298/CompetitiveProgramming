#include <cstring>
#include <iostream>
using namespace std;

const int INF = 2e9;

int n, ans, dp[128], w[1024], v[1024];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> n) {
		ans = 0;
		memset(dp, 0, sizeof(dp));

		for (int i = 0; i < n; i++)
			cin >> w[i] >> v[i];

		for (int i = 0; i < n; i++)
			for (int j = 100; j >= w[i]; j--)
				dp[j] = max(dp[j - w[i]] + v[i], dp[j]);

		cout << dp[100] << '\n';
	}
}
