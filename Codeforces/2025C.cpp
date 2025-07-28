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
		map<int, int> mp;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			mp[x]++;
		}

		vector<pair<int, int>> a;
		for (pair<int, int> p : mp) a.push_back(p);
		n = (int)a.size();
		int ans = 0, sum;
		for (int i = 0, j = 0; i < n; i++) {
			if (i == j) j = i + 1, sum = a[i].second;

			while (j < n && j - i < k && a[j].first == a[j - 1].first + 1) sum += a[j++].second;
			ans = max(ans, sum);
			sum -= a[i].second;
		}

		cout << ans << '\n';
	}
}
