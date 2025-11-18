#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<vector<int>> f(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			cin >> f[i][j];
		}
	}

	vector<pair<int, int>> dp(n + 1);
	for (int i = 0; i < n; i++) {
		dp[i].first = a[i];
		dp[i].second = -1;
		for (int j = 0; j < i; j++) {
			if (f[j][i] && dp[j].first + a[i] > dp[i].first) {
				dp[i] = make_pair(dp[j].first + a[i], j);
			}
		}
	}

	int ans = -0x3f3f3f3f;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[i].first);
	}

	vector<int> v;
	for (int i = 0; i < n; i++) {
		if (dp[i].first == ans) {
			v.push_back(i);
			pair<int, int> p = dp[i];
			while (p.second != -1) {
				v.push_back(p.second);
				p = dp[p.second];
			}
		}
	}
	reverse(v.begin(), v.end());
	for (int i = 0; i < (int)v.size(); i++) {
		cout << v[i] + 1 << " \n"[i + 1 == (int)v.size()];
	}
	cout << ans << '\n';
}
