#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int x, y, a;
		cin >> x >> y >> a;
		a %= (x + y);
		if (x > a) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
}
