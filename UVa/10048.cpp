#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;

int Case;
int dp[128][128];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int C, S, Q;

	while (cin >> C >> S >> Q && C) {
		memset(dp, 0x3f, sizeof(dp));

		for (int i = 0, u, v, d; i < S; i++) {
			cin >> u >> v >> d;
			dp[u][v] = dp[v][u] = d;
		}

		for (int k = 1; k <= C; k++)
			for (int i = 1; i <= C; i++)
				for (int j = 1; j <= C; j++)
					dp[i][j] = min(max(dp[i][k], dp[k][j]), dp[i][j]);

		if (Case)
			cout << '\n';
		cout << "Case #" << ++Case << '\n';
		while (Q--) {
			int c1, c2;

			cin >> c1 >> c2;
			if (dp[c1][c2] == INF)
				cout << "no path\n";
			else
				cout << dp[c1][c2] << '\n';
		}
	}
}
