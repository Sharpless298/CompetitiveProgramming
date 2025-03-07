#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, sum, mx, mn;

	cout << fixed << setprecision(2);

	while (cin >> n && n) {
		sum = 0;
		mx = -100;
		mn = 100;
		for (int i = 0, x; i < n; i++) {
			cin >> x;
			sum += x;
			mx = max(mx, x);
			mn = min(mn, x);
		}

		cout << ((double)sum - mx - mn) / (n - 2) << '\n';
	}
}
