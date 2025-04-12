#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;

	cin >> T;
	while (T--) {
		int n, k;

		cin >> n >> k;

		if (k == 0) {
			cout << 0 << '\n';
			continue;
		}

		k -= n;
		n--;
		int ans = 1;
		while (k > 0) {
			k -= n;
			ans++;
			if (k <= 0)
				break;
			k -= n;
			ans++;
			n--;
		}

		cout << ans << '\n';
	}
}
