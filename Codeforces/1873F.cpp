#include <iostream>
using namespace std;

int T, n, k, sum, ans;
int a[200005], h[200005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		sum = ans = 0;

		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> h[i];

		for (int i = 0, j = 0; i < n; i++) {
			while (j < n && (j <= i || !(h[j - 1] % h[j])) && sum + a[j] <= k)
				sum += a[j], j++;
			ans = max(ans, j - i);
			sum -= a[i];
		}

		cout << ans << '\n';
	}
}
