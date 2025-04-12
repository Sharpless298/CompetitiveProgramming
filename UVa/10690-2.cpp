#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	while (cin >> n >> m) {
		int N = n + m, sum = 0;
		vector<int> a(N);
		for (int &i : a)
			cin >> i, sum += i;

		vector<bitset<10001>> dp(n + 1);
		dp[0][0] = true;
		for (int i = 0; i < N; i++) {
			for (int j = n; j >= 1; j--)
				dp[j] |= dp[j - 1] << (a[i] + 50);
		}

		auto b = dp.back();
		int mn = INT_MAX, mx = INT_MIN;
		for (int i = 0; i <= 10000; i++) {
			if (b[i]) {
				mn = min(mn, (i - n * 50) * (sum - (i - n * 50)));
				mx = max(mx, (i - n * 50) * (sum - (i - n * 50)));
			}
		}

		cout << mx << ' ' << mn << '\n';
	}
}
