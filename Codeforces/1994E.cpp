#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int k;
		cin >> k;
		vector<int> a(k);
		for (int i = 0; i < k; i++) {
			cin >> a[i];
			for (int j = 0; j < a[i] - 1; j++) {
				int t;
				cin >> t;
			}
		}

		int ans = 0;
		sort(a.begin(), a.end(), greater());

		for (auto x : a) {
			for (int i = 23; i >= 0; i--) {
				int p = (ans >> i) & 1, q = (x >> i) & 1;
				if (q == 0)
					continue;

				if (p == 0)
					ans |= (1 << i);
				else {
					ans |= (1 << i) - 1;
					break;
				}
			}
		}
		cout << ans << '\n';
	}
}
