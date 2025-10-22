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
		long long sum = 0, mx = 0, d = 0, ans = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			sum += x;
			mx = max(mx, sum);
			if (sum - mx < d) {
				d = sum - mx;
				ans = mx;
			}
		}
		cout << ans << '\n';
	}
}
