#include <iostream>
using namespace std;

typedef long long int lli;

lli a[200005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, n;
	lli sum, ans, mx;

	cin >> T;
	while (T--) {
		ans = 0;

		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];

		sum = 0;
		mx = 0;
		for (int i = 0; i < n; i++) {
			mx = max(mx, a[i]);
			sum += a[i];
			if (mx == sum - mx)
				ans++;
		}

		cout << ans << '\n';
	}
}
