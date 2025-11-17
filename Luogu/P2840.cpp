#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, w;
	cin >> n >> w;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> dp(w + 1);
	dp[0] = 1;
	for (int i = 1; i <= w; i++) {
		for (int j = 0; j < n; j++) {
			if (i - a[j] >= 0) {
				dp[i] = (dp[i] + dp[i - a[j]]) % MOD;
			}
		}
	}

	cout << dp[w] << '\n';
}
