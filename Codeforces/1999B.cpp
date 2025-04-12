#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int a1, a2, b1, b2;
		cin >> a1 >> a2 >> b1 >> b2;

		int ans = 0;
		if ((a1 > b1 && a2 >= b2) || (a1 >= b1 && a2 > b2))
			ans++;
		if ((a1 > b2 && a2 >= b1) || (a1 >= b2 && a2 > b1))
			ans++;

		cout << ans * 2 << '\n';
	}
}
