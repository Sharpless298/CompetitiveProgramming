#include <iostream>
using namespace std;

int a[100005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, n, ans;

	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];

		ans = a[n - 1];
		for (int i = n - 2; i >= 0; i--)
			ans = max(ans + 1, a[i]);

		cout << ans << '\n';
	}
}
