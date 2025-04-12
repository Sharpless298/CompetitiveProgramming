#include <iostream>
using namespace std;

typedef long long int lli;

lli a[100005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, n;
	lli l, r, sum, ans;

	cin >> T;
	while (T--) {
		sum = ans = 0;

		cin >> n >> l >> r;
		for (int i = 0; i < n; i++)
			cin >> a[i];

		for (int i = 0, j = 0; i < n; i++) {
			while (j < n && sum < l)
				sum += a[j++];
			if (sum >= l && sum <= r) {
				ans++;
				i = j - 1;
				sum = 0;
				continue;
			}
			sum -= a[i];
		}

		cout << ans << '\n';
	}
}
