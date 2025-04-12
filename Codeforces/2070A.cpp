#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;

		cout << (n / 15 * 3 + min(3, n % 15 + 1)) << '\n';
	}
}
