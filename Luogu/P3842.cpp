#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> l(n), r(n);
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
	}

	vector<vector<int>> dp(n, vector<int>(2));
	dp[0][0] = r[0] - 1 + r[0] - l[0];
	dp[0][1] = r[0] - 1;
	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][0] + abs(r[i] - l[i - 1]) + 1 + r[i] - l[i], dp[i - 1][1] + abs(r[i - 1] - r[i]) + 1 + r[i] - l[i]);
		dp[i][1] = min(dp[i - 1][0] + abs(l[i] - l[i - 1]) + 1 + r[i] - l[i], dp[i - 1][1] + abs(r[i - 1] - l[i]) + 1 + r[i] - l[i]);
	}

	cout << min(dp[n - 1][0] + n - l[n - 1], dp[n - 1][1] + n - r[n - 1]);
}
