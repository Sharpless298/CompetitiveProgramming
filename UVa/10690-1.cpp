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

		vector<vector<bool>> dp(n + 1, vector<bool>(5001));
		dp[0][2500] = true;
		for (int i = 0; i < N; i++)
			for (int j = min(n, i + 1); j >= 1; j--)
				for (int k = 0; k <= 5000; k++)
					if (dp[j][k])
						dp[j + 1][k + a[i]] = true;

		int mn = INT_MAX, mx = INT_MIN;
		for (int i = 0; i <= 5000; i++) {
			if (dp[n][i]) {
				mn = min(mn, (i - 2500) * (sum - (i - 2500)));
				mx = max(mx, (i - 2500) * (sum - (i - 2500)));
			}
		}

		cout << mx << ' ' << mn << '\n';
	}
}
