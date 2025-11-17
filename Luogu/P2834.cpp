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
	for (int i = 0; i < n; i++) {
		for (int j = a[i]; j <= w; j++) {
			dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
		}
	}
	cout << dp[w] << '\n';
}
