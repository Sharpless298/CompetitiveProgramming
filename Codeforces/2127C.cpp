#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		vector<pair<int, int>> p(n);
		for (auto &i : p) cin >> i.first;
		for (auto &i : p) cin >> i.second;

		long long sum = 0;
		for (int i = 0; i < n; i++) {
			if (p[i].first < p[i].second) swap(p[i].first, p[i].second);
			sum += p[i].first - p[i].second;
		}
		sort(p.begin(), p.end());

		int d = -0x3f3f3f3f;
		for (int i = n - 1; i > 0; i--)
			d = max(d, p[i - 1].first - p[i].second);

		cout << (d > 0 ? sum : sum - 2 * d) << '\n';
	}
}
