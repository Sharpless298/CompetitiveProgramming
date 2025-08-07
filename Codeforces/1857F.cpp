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
		map<long long, long long> mp;
		for (int i = 0; i < n; i++) {
			long long x;
			cin >> x;
			mp[x]++;
		}

		int q;
		cin >> q;
		while (q--) {
			long long x, y;
			cin >> x >> y;

			long long z = x * x - 4 * y, sqrtz = sqrt(z);
			if (x * x - 4 * y < 0 || sqrtz * sqrtz != z) {
				cout << 0 << ' ';
			} else {
				if ((sqrtz + x) & 1) {
					cout << 0 << ' ';
				} else {
					long long a = (x + sqrtz) / 2;

					if (a == x - a) {
						cout << mp[a] * (mp[a] - 1) / 2 << ' ';
					} else {
						cout << mp[a] * mp[x - a] << ' ';
					}
				}
			}
		}
		cout << '\n';
	}
}
