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
		vector<int> v;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			v.push_back(a[i]);
		}
		vector<int> b(n);
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			v.push_back(b[i]);
		}

		sort(v.begin(), v.end());
		v.resize(unique(v.begin(), v.end()) - v.begin());

		for (int i = 0; i < n; i++) {
			a[i] = (int)(lower_bound(v.begin(), v.end(), a[i]) - v.begin());
			b[i] = (int)(lower_bound(v.begin(), v.end(), b[i]) - v.begin());
		}

		vector<int> c(v.size() + 1), d(v.size() + 1);
		for (int i = 0; i < n; i++) {
			c[0]++, c[b[i] + 1]--;
			d[a[i] + 1]++, d[b[i] + 1]--;
		}

		for (int i = 1; i < (int)v.size(); i++) {
			c[i] += c[i - 1];
			d[i] += d[i - 1];
		}

		long long ans = 0;
		for (int i = 0; i < (int)v.size(); i++) {
			if (d[i] <= k) {
				ans = max(ans, 1LL * c[i] * v[i]);
			}
		}

		cout << ans << '\n';
	}
}
