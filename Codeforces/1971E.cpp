#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, k, q;

		cin >> n >> k >> q;
		vector<int> a(k + 1);
		a[0] = 0;
		for (int i = 1; i <= k; i++)
			cin >> a[i];
		vector<int> b(k + 1);
		b[0] = 0;
		for (int i = 1; i <= k; i++)
			cin >> b[i];

		while (q--) {
			int d;
			cin >> d;

			if (d == n) {
				cout << b[k] << ' ';
				continue;
			}

			int idx = (int)(upper_bound(a.begin(), a.end(), d) - a.begin());
			cout << b[idx - 1] + ((1LL * d - a[idx - 1]) * (b[idx] - b[idx - 1]) / (a[idx] - a[idx - 1])) << ' ';
		}
		cout << '\n';
	}
}
