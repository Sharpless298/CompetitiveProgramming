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
		vector<int> a(n);
		for (int &i : a) cin >> i;

		if (n != 2) {
			cout << "NO\n";
		} else {
			if (a[1] == a[0] + 1) {
				cout << "NO\n";
			} else {
				cout << "YES\n";
			}
		}
	}
}
