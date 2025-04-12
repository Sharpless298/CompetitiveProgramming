#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		long long x, y;
		cin >> x >> y;

		if (x == y) {
			cout << -1 << '\n';
		} else {
			cout << (1LL << 32) - max(x, y) << '\n';
		}
	}
}
