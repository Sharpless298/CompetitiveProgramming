#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int M, N, a, b, c, d;
int dp[100][200][200];

int f(int i, int y, int x) {
	return (a * i + b * x + c * y) % d;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(dp, 0, sizeof(dp));

	cin >> M >> N >> a >> b >> c >> d;

	for (int i = 0; i < M - N + 1; i++) {
		for (int j = 0; j < M - N + 1; j++) {
			if (i == 0 && j == 0)
				dp[0][0][0] = 0;
			else if (i == 0)
				dp[0][i][j] = max(dp[0][i][j - 1], f(0, i, j));
			else if (j == 0)
				dp[0][i][j] = max(dp[0][i - 1][j], f(0, i, j));
			else
				dp[0][i][j] = max({dp[0][i - 1][j], dp[0][i][j - 1], f(0, i, j)});
		}
	}
	for (int i = 1; i < N; i++)
		for (int j = i; j < M - N + i + 1; j++)
			for (int k = i; k < M - N + i + 1; k++)
				dp[i][j][k] = max({dp[i][j - 1][k], dp[i][j][k - 1], dp[i - 1][j - 1][k - 1] + f(i, j, k)});

	cout << dp[N - 1][M - 1][M - 1] << '\n';
}
