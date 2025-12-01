#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, K;
	cin >> n >> K;
	K = min(K, n);
	vector<vector<long long>> a(n, vector<long long>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> a[i][j];
		}
	}

	reverse(a.begin(), a.end());
	vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(K + 1)));
	for (int i = 0; i < n; i++) {
		dp[0][i][0] = a[0][i];
	}
	if (K > 0) {
		for (int i = 0; i < n; i++) {
			dp[0][i][1] = 3 * a[0][i];
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			for (int k = 0; k <= min(K, i + 1); k++) {
				if (i + 1 == k) {
					dp[i][j][k] = max(dp[i - 1][j][k - 1], dp[i - 1][j + 1][k - 1]) + 3 * a[i][j];
					continue;
				}

				dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j + 1][k]) + a[i][j];
				if (k > 0) {
					dp[i][j][k] = max({dp[i][j][k], dp[i - 1][j][k - 1] + 3 * a[i][j], dp[i - 1][j + 1][k - 1] + 3 * a[i][j]});
				}
			}
		}
	}

	cout << *max_element(dp[n - 1][0].begin(), dp[n - 1][0].end()) << '\n';
}
