#include <bits/stdc++.h>
using namespace std;

int query(int i) {
	cout << "? " << i + 1 << endl;
	int ret;
	cin >> ret;
	return ret;
}

signed main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int ans = 0;
		for (int i = 0; i < n / k; i++) {
			ans ^= query(k * i);
		}
		for (int i = k * (n / k); i < n; i += 2) {
			ans ^= query(i - k + 1) ^ query(i - k + 2);
		}
		cout << "! " << ans << endl;
	}
}
