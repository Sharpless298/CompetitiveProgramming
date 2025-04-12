#include <iostream>
using namespace std;

void solve() {
	int n;
	cin >> n;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (i != n - 2)
			ans += x;
		else
			ans -= x;
	}

	cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--)
		solve();
}
