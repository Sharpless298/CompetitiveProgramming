#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, ans = 1;

	cin >> n;

	if (n & 1)
		cout << 0 << '\n';
	else {
		for (int i = 0; i < n; i += 2)
			ans *= 2;

		cout << ans << '\n';
	}
}
