#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, w;
	cin >> n >> w;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> dp(w + 1, 0x3f3f3f3f);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = a[i]; j <= w; j++) {
			dp[j] = min(dp[j], dp[j - a[i]] + 1);
		}
	}
	cout << dp[w] << '\n';
}
