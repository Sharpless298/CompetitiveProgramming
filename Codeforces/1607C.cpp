#include <algorithm>
#include <iostream>
using namespace std;

int T, n, ans;
int a[200005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];

		sort(a, a + n);
		ans = a[0];
		for (int i = 1; i < n; i++)
			ans = max(ans, a[i] - a[i - 1]);

		cout << ans << '\n';
	}
}
