#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(m, make_pair(-0x3f3f3f3f, 0)));
	dp[0][0].first = a[0][0];
	for (int i = 1; i < m; i++) {
		dp[0][i].first = a[0][i];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < j; k++) {
				if (dp[i - 1][k].first + a[i][j] > dp[i][j].first) {
					dp[i][j].first = dp[i - 1][k].first + a[i][j];
					dp[i][j].second = k;
				}
			}
		}
	}
	int ans = -0x3f3f3f3f, pos = -1;
	for (int i = 0; i < m; i++) {
		if (dp[n - 1][i].first > ans) {
			ans = dp[n - 1][i].first;
			pos = i;
		}
	}
	cout << ans << '\n';

	vector<int> v;
	v.push_back(pos);
	pair<int, int> p = dp[n - 1][pos];
	for (int j = n - 2; j >= 0; j--) {
		v.push_back(p.second);
		p = dp[j][p.second];
	}

	reverse(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		cout << v[i] + 1 << " \n"[i + 1 == n];
	}
}
