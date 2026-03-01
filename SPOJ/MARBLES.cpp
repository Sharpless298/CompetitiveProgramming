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
		n--, k--;

		if (k > n - k) {
			k = n - k;
		}
		long long ans = 1;
		for (int i = 0; i < k; i++) {
			ans = ans * (n - i) / (i + 1);
		}
		cout << ans << '\n';
	}
}
