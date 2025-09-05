#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		long long ans = -0x3fffff'fffff'fffff;
		for (int i = 0; i < min(n, 100); i++) {
			for (int j = i + 1; j < min(n, 100); j++) {
				ans = max(ans, 1LL * (i + 1) * (j + 1) - k * (a[i] | a[j]));
			}
		}
		for (int i = max(n - 300, 0); i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ans = max(ans, 1LL * (i + 1) * (j + 1) - k * (a[i] | a[j]));
			}
		}

		cout << ans << '\n';
	}
}
