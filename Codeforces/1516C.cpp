#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int sum = 0;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum & 1) {
		cout << 0 << '\n';
		return 0;
	}

	vector<bool> dp(sum / 2 + 1);
	dp[0] = true;
	for (int i = 0; i < n; i++) {
		for (int j = sum / 2 - a[i]; j >= 0; j--) {
			dp[j + a[i]] = dp[j + a[i]] | dp[j];
		}
	}

	if (dp.back()) {
		cout << 1 << '\n';
		pair<int, int> mn = make_pair(0x3f3f3f3f, 0);
		for (int i = 0; i < n; i++) {
			mn = min(mn, make_pair(__builtin_ctz(a[i]), i + 1));
		}
		cout << mn.second << '\n';
	} else {
		cout << 0 << '\n';
	}
}
