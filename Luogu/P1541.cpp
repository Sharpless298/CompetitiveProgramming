#include <iostream>
#include <vector>

using namespace std;

int dp[64][64][64][64];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> ary(n);
	for (int i = 0; i < n; i++)
		cin >> ary[i];
	vector<int> cnt(5);
	for (int i = 0, x; i < m; i++)
		cin >> x, cnt[x]++;

	dp[0][0][0][0] = ary[0];
	for (int a = 0; a <= cnt[1]; a++) {
		for (int b = 0; b <= cnt[2]; b++) {
			for (int c = 0; c <= cnt[3]; c++) {
				for (int d = 0; d <= cnt[4]; d++) {
					int k = a + 2 * b + 3 * c + 4 * d;
					if (a != 0)
						dp[a][b][c][d] = max(dp[a][b][c][d], dp[a - 1][b][c][d] + ary[k]);
					if (b != 0)
						dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b - 1][c][d] + ary[k]);
					if (c != 0)
						dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c - 1][d] + ary[k]);
					if (d != 0)
						dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c][d - 1] + ary[k]);
				}
			}
		}
	}

	cout << dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]] << '\n';
}
