#include <iostream>
using namespace std;

typedef long long int lli;

int a[100005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, n;
	lli p, d, sum, mx;

	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];

		p = sum = mx = 0;
		for (int i = 0; i < n; i++) {
			p = max(p, 1LL * a[i]);

			d = p - a[i];
			sum += d;
			mx = max(mx, d);
		}

		cout << sum + mx << '\n';
	}
}
