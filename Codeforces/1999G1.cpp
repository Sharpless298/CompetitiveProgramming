#include <iostream>
using namespace std;

signed main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int l = 2, r = 1000;
		while (l < r) {
			int m = (l + r) / 2;

			cout << "? 1 " << m << endl;
			int t;
			cin >> t;

			if (t == m)
				l = m + 1;
			else
				r = m;
		}
		cout << "! " << l << '\n';
	}
}
