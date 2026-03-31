#include <bits/stdc++.h>
using namespace std;

signed main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		auto query = [](int i, int j) {
			cout << "? " << i + 1 << ' ' << j + 1 << endl;
			int ret;
			cin >> ret;
			return ret;
		};

		int ans = -1;
		for (int i = 0; i < n - 1; i += 2) {
			int c = query(i, i + 1) + query(i + 1, i);
			if (c == 1) {
				ans = i;
			}
		}

		if (ans == -1) {
			cout << "! " << n << endl;
		} else {
			for (int i = 0; i < n; i++) {
				if (i != ans && i != ans + 1) {
					int c = query(ans, i) + query(i, ans);
					if (c != 1) {
						ans++;
					}
					break;
				}
			}
			cout << "! " << ans + 1 << endl;
		}
	}
}
