#include <bits/stdc++.h>
using namespace std;

const int shift = 400000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}

	vector<int> dp(shift * 2 + 1, -0x3f3f3f3f);
	dp[shift] = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] >= 0) {
			for (int j = shift * 2; j >= a[i]; j--) {
				dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
			}
		} else {
			for (int j = 0; j <= a[i] + 2 * shift; j++) {
				dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
			}
		}
	}

	int ans = 0;
	for (int i = shift; i <= 2 * shift; i++) {
		if (dp[i] >= 0) {
			ans = max(ans, i - shift + dp[i]);
		}
	}
	cout << ans << '\n';
}
