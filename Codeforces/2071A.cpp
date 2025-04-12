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
		cout << ((k - 1) % 3 == 0 ? "YES\n" : "NO\n");
	}
}
