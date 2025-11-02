#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x > m / 2) {
				a.push_back(x);
			}
		}

		if (m == 1) {
			cout << 0 << '\n';
			continue;
		}

		sort(a.begin(), a.end());
		a.resize(unique(a.begin(), a.end()) - a.begin());
		n = (int)a.size();
		int ans = 0x3f3f3f3f;
		vector<int> b((m + 1) / 2);
		for (int i = 0, j = 0, cnt = 0; i < n; i++) {
			while (j < n && cnt < (m + 1) / 2) {
				for (int x = a[j], k = m / 2 + 1; x >= k && k <= m; k++) {
					if (x % k == 0) {
						if (b[k - m / 2 - 1] == 0) {
							cnt++;
						}
						b[k - m / 2 - 1]++;
					}
				}
				j++;
			}

			if (cnt == (m + 1) / 2) {
				ans = min(ans, a[j - 1] - a[i]);
			}

			for (int k = m / 2 + 1; a[i] >= k && k <= m; k++) {
				if (a[i] % k == 0) {
					if (b[k - m / 2 - 1] == 1) {
						cnt--;
					}
					b[k - m / 2 - 1]--;
				}
			}
		}

		cout << (ans == 0x3f3f3f3f ? -1 : ans) << '\n';
	}
}
