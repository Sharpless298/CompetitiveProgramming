#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, a, b;

	cin >> T;
	while (T--) {
		cin >> a >> b;
		int p = (2 * a - b) / 3, q = (2 * a - b) % 3, r = (b - p) / 2, s = (b - p) % 2;

		cout << (p >= 0 && r >= 0 && q == 0 && s == 0 ? "YES\n" : "NO\n");
	}
}
