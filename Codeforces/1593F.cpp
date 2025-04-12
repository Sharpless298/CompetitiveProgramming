#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, a, b;
		string s;
		cin >> n >> a >> b >> s;

		bool dp[n + 1][n + 1][a][b];
		for (int i = 0; i < n + 1; i++)
			for (int j = 0; j < n + 1; j++)
				for (int k = 0; k < a; k++)
					for (int l = 0; l < b; l++)
						dp[i][j][k][l] = false;
		array<int, 4> p[n + 1][n + 1][a][b];
		for (int i = 0; i < n + 1; i++)
			for (int j = 0; j < n + 1; j++)
				for (int k = 0; k < a; k++)
					for (int l = 0; l < b; l++)
						p[i][j][k][l] = {-1, -1, -1, -1};

		dp[0][0][0][0] = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				for (int k = 0; k < a; k++) {
					for (int l = 0; l < b; l++) {
						if (!dp[i][j][k][l])
							continue;

						int nk = (k * 10 + s[i] - '0') % a;
						dp[i + 1][j + 1][nk][l] = true;
						p[i + 1][j + 1][nk][l] = {i, j, k, l};

						int nl = (l * 10 + s[i] - '0') % b;
						dp[i + 1][j][k][nl] = true;
						p[i + 1][j][k][nl] = {i, j, k, l};
					}
				}
			}
		}

		int best = -1;
		for (int i = 1; i < n; i++)
			if (dp[n][i][0][0] && abs(n - i - i) < abs(n - best - best))
				best = i;

		if (best == -1) {
			cout << -1 << '\n';
		} else {
			string ans = "";
			auto t = p[n][best][0][0];
			while (t[0] != -1) {
				if (t[1] != best)
					ans += 'R';
				else
					ans += 'B';
				best = t[1];
				t = p[t[0]][t[1]][t[2]][t[3]];
			}
			reverse(ans.begin(), ans.end());
			cout << ans << '\n';
		}
	}
}
