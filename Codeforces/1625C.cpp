#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, l, k;
	cin >> n >> l >> k;
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	d.push_back(l);

	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0x3f3f3f3f));
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			for (int p = i - 1; p >= 0; p--) {
				int q = j - (i - p - 1);
				if (q >= 0) {
					dp[i][j] = min(dp[i][j], dp[p][q] + a[p] * (d[i] - d[p]));
				}
			}
		}
	}

	cout << *min_element(dp.back().begin(), dp.back().end()) << '\n';
}
