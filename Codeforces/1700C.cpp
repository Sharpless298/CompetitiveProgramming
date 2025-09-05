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

		long long cur = a[0];
		long long ans = 0;
		for (int i = 0; i < n - 1; i++) {
			ans += abs(a[i] - a[i + 1]);
			if (a[i] > a[i + 1]) {
				cur += a[i + 1] - a[i];
			}
		}
		ans += abs(cur);
		cout << ans << '\n';
	}
}
