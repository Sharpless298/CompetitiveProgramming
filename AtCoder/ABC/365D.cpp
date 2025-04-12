#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	const int R = 0, P = 1, S = 2;
	int n;
	cin >> n;
	vector<int> a(n);
	map<char, int> mp;
	mp['R'] = 0, mp['P'] = 1, mp['S'] = 2;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		a[i] = mp[c];
	}

	array<array<int, 3>, 3> f;
	f[R][R] = 0, f[R][P] = -0x3f3f3f3f, f[R][S] = 1;
	f[P][R] = 1, f[P][P] = 0, f[P][S] = -0x3f3f3f3f;
	f[S][R] = -0x3f3f3f3f, f[S][P] = 1, f[S][S] = 0;

	vector<vector<int>> dp(n, vector<int>(3));
	dp[0][R] = f[R][a[0]];
	dp[0][P] = f[P][a[0]];
	dp[0][S] = f[S][a[0]];
	for (int i = 1; i < n; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				if (j != k)
					dp[i][j] = max(dp[i][j], dp[i - 1][k] + f[j][a[i]]);

	cout << *max_element(dp[n - 1].begin(), dp[n - 1].end()) << '\n';
}
