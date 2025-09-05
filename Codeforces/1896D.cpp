#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		set<int> pos;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] == 1) {
				pos.insert(i);
			}
		}

		while (q--) {
			int op;
			cin >> op;
			if (op == 1) {
				int s;
				cin >> s;
				if ((s - (int)pos.size()) & 1) {
					if ((int)pos.size() == 0) {
						cout << "NO\n";
					} else {
						int sum1 = 2 * *pos.rbegin() - ((int)pos.size() - 1);
						int sum2 = 2 * (n - *pos.begin() - 1) - ((int)pos.size() - 1);
						if (s <= max(sum1, sum2)) {
							cout << "YES\n";
						} else {
							cout << "NO\n";
						}
					}
				} else {
					if (s <= 2 * n - (int)pos.size()) {
						cout << "YES\n";
					} else {
						cout << "NO\n";
					}
				}

			} else {
				int i;
				cin >> i;
				i--;
				pos.erase(i);
				cin >> a[i];
				if (a[i] == 1) {
					pos.insert(i);
				}
			}
		}
	}
}
