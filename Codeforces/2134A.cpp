#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;
		if (n & 1) {
			if ((a > b && (a % 2 == 0)) || (b % 2 == 0)) {
				cout << "NO\n";
			} else {
				cout << "YES\n";
			}
		} else {
			if ((a > b && (a % 2 == 1)) || (b % 2 == 1)) {
				cout << "NO\n";
			} else {
				cout << "YES\n";
			}
		}
	}
}
