#include <bits/stdc++.h>
using namespace std;

int query(int a, int b) {
	cout << "? " << a << ' ' << b << endl;

	int ret;
	cin >> ret;
	return ret;
}

signed main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector<int> a(1 << n), b;
		iota(a.begin(), a.end(), 1);
		while (a.size() > 2) {
			for (int j = 0; j < (int)a.size(); j += 4) {
				int x = query(a[j], a[j + 2]), p, q;
				if (x == 0) {
					p = a[j + 1], q = a[j + 3];
				} else if (x == 1) {
					p = a[j], q = a[j + 3];
				} else {
					p = a[j + 1], q = a[j + 2];
				}
				int y = query(p, q);
				if (y == 1) {
					b.push_back(p);
				} else if (y == 2) {
					b.push_back(q);
				}
			}
			a = b;
			b.clear();
		}
		int ans = a[0];
		if (a.size() == 2) {
			int x = query(a[0], a[1]);
			ans = (x == 1 ? a[0] : a[1]);
		}

		cout << "! " << ans << endl;
	}
}
