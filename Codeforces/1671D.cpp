#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		long long ans = 0;
		for (int i = 1; i < n; i++) {
			ans += abs(a[i] - a[i - 1]);
		}

		{
			int mn = 0x3f3f3f3f;
			mn = min(mn, abs(a[0] - 1));
			mn = min(mn, abs(a[n - 1] - 1));
			for (int i = 0; i < n; i++) {
				mn = min(mn, 2 * abs(a[i] - 1));
			}
			ans += mn;
		}
		if (x > *max_element(a.begin(), a.end())) {
			int mn = 0x3f3f3f3f;
			mn = min(mn, abs(a[0] - x));
			mn = min(mn, abs(a[n - 1] - x));
			for (int i = 0; i < n; i++) {
				mn = min(mn, 2 * abs(a[i] - x));
			}
			ans += mn;
		}

		cout << ans << '\n';
	}
}
