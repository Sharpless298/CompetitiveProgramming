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
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int t;
			cin >> t;
			sum += t;
		}

		cout << (((sum % x) == 0 && (sum / n) == x) ? "YES\n" : "NO\n");
	}
}
