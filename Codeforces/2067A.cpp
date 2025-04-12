#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int x, y;
		cin >> x >> y;
		if (x + 1 == y || (x > y && (x - (y - 1)) % 9 == 0)) {
			cout << "YES\n";
		} else
			cout << "NO\n";
	}
}
