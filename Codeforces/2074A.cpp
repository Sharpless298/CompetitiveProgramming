#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int l, r, d, u;
		cin >> l >> r >> d >> u;

		if (l == r && r == d && d == u)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}
