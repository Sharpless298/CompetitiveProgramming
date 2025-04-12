#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int INF = 2147483647;

int T, n, m, ans;
int dis[32][32], dp[32][1 << 16];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		ans = INF;

		cin >> n;
		for (int i = 0, x; i < n; i++)
			for (int j = i + 1; j < n; j++)
				cin >> x, dis[i][j] = dis[j][i] = x;
		m = (1 << n);

		memset(dp, 0x3f3f3f3f, sizeof(dp));
		dp[0][1] = 0;
		for (int i = 0; i < (1 << n); i++) {
			for (int j = 0; j < n; j++) {
				if (!(i & (1 << j)))
					continue;

				for (int k = 0; k < n; k++)
					if (i & (1 << k))
						dp[j][i] = min(dp[k][i ^ (1 << j)] + dis[j][k], dp[j][i]);
			}
		}
		for (int i = 0; i < n; i++)
			ans = min(dp[i][m - 1] + dis[i][0], ans);

		cout << ans << '\n';
	}
}
