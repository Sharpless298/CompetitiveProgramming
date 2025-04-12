#include <iostream>
using namespace std;

signed main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int l = 1, r = 999;
		while (r - l > 1) {
			int ml = (2 * l + r) / 3, mr = (l + 2 * r) / 3;

			cout << "? " << ml << ' ' << mr << endl;
			int t;
			cin >> t;

			if (t == ml * mr)
				l = mr;
			else if (t == ml * (mr + 1))
				l = ml, r = mr;
			else
				r = ml;
		}

		cout << "! " << r << '\n';
	}
}
