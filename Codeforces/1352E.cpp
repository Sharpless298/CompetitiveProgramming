#include <iostream>
using namespace std;

int a[8005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, n, sum, ans;

	cin >> T;
	while (T--) {
		ans = 0;

		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];

		for (int i = 0; i < n; i++) {
			sum = 0;
			for (int j = 0, k = 0; j < n; j++) {
				while (sum < a[i] && k < n)
					sum += a[k++];

				if (sum == a[i] && k - j >= 2) {
					ans++;
					break;
				}
				sum -= a[j];
			}
		}

		cout << ans << '\n';
	}
}
