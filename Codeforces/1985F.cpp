#include <iostream>
using namespace std;

typedef long long int lli;

int a[200005], c[200005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, n;
	lli l, r, m, sum, h;

	cin >> T;
	while (T--) {
		cin >> h >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> c[i];

		l = 0, r = 4e10 + 5;
		while (l < r) {
			m = (l + r) >> 1, sum = 0;

			for (int i = 0; i < n; i++) {
				sum += (1 + m / c[i]) * a[i];
				if (sum >= h)
					break;
			}

			if (sum < h)
				l = m + 1;
			else
				r = m;
		}

		cout << l + 1 << '\n';
	}
}
