#include <iostream>
using namespace std;

int T, n, ans, a[50005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		ans = 0x3f3f3f3f;

		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];

		for (int i = 0; i < n - 1; i++)
			ans = min(ans, max(a[i], a[i + 1]));

		cout << ans - 1 << '\n';
	}
}
