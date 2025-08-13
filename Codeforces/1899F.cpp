#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, q;
		cin >> n >> q;
		vector<int> d(q);
		for (int i = 0; i < q; i++) {
			cin >> d[i];
		}

		cout << 1 << ' ' << n - 1 << '\n';
		for (int i = 0; i < n - 3; i++) {
			cout << n - 1 - i << ' ' << n - 2 - i << '\n';
		}
		cout << 2 << ' ' << n << '\n';

		int last = n - 1;
		for (int i = 0; i < q; i++) {
			if (last == d[i]) {
				cout << "-1 -1 -1\n";
			} else {
				cout << 1 << ' ' << last << ' ' << d[i] << '\n';
				last = d[i];
			}
		}
	}
}
