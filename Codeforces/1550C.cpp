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

		auto f = [](int u, int v, int w) {
			if (u <= v && v <= w) {
				return false;
			}
			if (w <= v && v <= u) {
				return false;
			}
			return true;
		};
		int ans = n + (n - 1);
		for (int i = 0; i < n - 2; i++) {
			ans += f(a[i], a[i + 1], a[i + 2]);
		}
		for (int i = 0; i < n - 3; i++) {
			ans += (f(a[i], a[i + 1], a[i + 2]) && f(a[i], a[i + 1], a[i + 3]) &&
					f(a[i], a[i + 2], a[i + 3]) && f(a[i + 1], a[i + 2], a[i + 3]));
		}
		cout << ans << '\n';
	}
}
