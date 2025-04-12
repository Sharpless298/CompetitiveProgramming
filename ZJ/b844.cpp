#include <algorithm>
#include <iostream>
using namespace std;

int n, q, ary[500005], ans, t;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> n >> q) {
		for (int i = 0; i < n; i++)
			cin >> ary[i];

		sort(ary, ary + n);
		while (q--) {
			cin >> t;

			cout << ((upper_bound(ary, ary + n, t) - ary) & 1) << '\n';
		}
	}
}
