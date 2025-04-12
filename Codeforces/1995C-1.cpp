#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;
typedef long double ld;

const ld EPS = 1e-9;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;

	cin >> T;
	while (T--) {
		int n;

		cin >> n;

		bool f = false;
		vector<ld> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i != 0 && a[i] == 1 && a[i - 1] > 1)
				f = true;
		}

		if (f) {
			cout << -1 << '\n';
			continue;
		}

		for (int i = 0; i < n; i++)
			a[i] = log(log(a[i]));

		lli ans = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] < a[i - 1]) {
				ld k = ceil((a[i - 1] - a[i]) / log(2) - EPS);
				ans += (int)k;
				a[i] += k * log(2);
			}
		}

		cout << ans << '\n';
	}
}
