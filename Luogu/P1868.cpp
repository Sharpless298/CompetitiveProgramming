#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int, int>> p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i].first >> p[i].second;
	sort(p.begin(), p.end(), [](pair<int, int> &a, pair<int, int> &b) { return a.second < b.second; });

	auto f = [&](int l, int r, int k) {
		while (l < r) {
			int m = (l + r) >> 1;
			if (p[m].second < k)
				l = m + 1;
			else
				r = m;
		}
		return l - 1;
	};
	vector<int> dp(n);
	dp[0] = p[0].second - p[0].first + 1;
	for (int i = 1; i < n; i++)
		dp[i] = max(dp[i - 1], dp[f(0, i, p[i].first)] + p[i].second - p[i].first + 1);

	cout << dp[n - 1] << '\n';
}
