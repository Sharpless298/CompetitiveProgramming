#include <iostream>
using namespace std;

const int INF = 2e9;

int n, ary[64], dp[64][64];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> ary[i];

	for (int i = 2; i < n; i++) {
		for (int l = 0, r = i; r < n; l++, r++) {
			dp[l][r] = INF;
			for (int k = l + 1; k < r; k++)
				dp[l][r] = min(dp[l][r], dp[l][k] + dp[k][r] + ary[l] * ary[k] * ary[r]);
		}
	}

	cout << dp[0][n - 1] << '\n';
}
