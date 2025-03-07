#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, n, p, q;

	cin >> T;
	while (T--) {
		cin >> n;

		cout << (n == 3 ? 3 : 2) << '\n';
	}
}
