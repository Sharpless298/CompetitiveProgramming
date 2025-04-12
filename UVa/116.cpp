#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

const lli INF = 9e18;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	while (cin >> n >> m) {
		vector<vector<lli>> G(n, vector<lli>(m));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> G[i][j];

		int f;
		lli ans = INF;
		vector<vector<lli>> dp(n, vector<lli>(m));
		vector<vector<int>> nxt(n, vector<int>(m));
		for (int i = m - 1; i >= 0; i--) {
			for (int j = 0; j < n; j++) {
				if (i == m - 1)
					dp[j][i] = G[j][i];
				else {
					dp[j][i] = INF;

					int c[3] = {(j + 1 + n) % n, j, (j - 1 + n) % n};
					sort(c, c + 3);
					for (int k = 0; k < 3; k++) {
						if (dp[c[k]][i + 1] + G[j][i] < dp[j][i]) {
							dp[j][i] = dp[c[k]][i + 1] + G[j][i];
							nxt[j][i] = c[k];
						}
					}
				}
				if (i == 0 && dp[j][i] < ans)
					ans = dp[j][i], f = j;
			}
		}

		for (int i = f, j = 0; j < m; i = nxt[i][j++])
			cout << i + 1 << " \n"[j + 1 == m];
		cout << ans << '\n';
	}
}
