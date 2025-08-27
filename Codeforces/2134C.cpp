#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		long long ans = 0;
		for (int i = 0; i < n; i += 2) {
			for (int j : {i - 1, i + 1}) {
				if (0 <= j && j < n) {
					if (a[i] > a[j]) {
						ans += a[i] - a[j];
						a[i] = a[j];
					}
				}
			}
		}

		for (int i = 2; i < n; i += 2) {
			if (a[i] + a[i - 2] > a[i - 1]) {
				ans += a[i] + a[i - 2] - a[i - 1];
				a[i] -= a[i] + a[i - 2] - a[i - 1];
			}
		}

		cout << ans << '\n';
	}
}
