#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m));
		vector<pair<long long, int>> sum(n);
		for (int i = 0; i < n; i++) {
			sum[i].second = i;
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				sum[i].first += a[i][j];
			}
		}
		sort(sum.begin(), sum.end(), greater<pair<long long, int>>());
		long long ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				ans += 1LL * a[sum[i].second][j] * (n * m - (i * m + j));
		cout << ans << '\n';
	}
}
