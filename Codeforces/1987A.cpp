#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, n, k;

	cin >> T;
	while (T--) {
		cin >> n >> k;

		cout << (n - 1) * k + 1 << '\n';
	}
}
