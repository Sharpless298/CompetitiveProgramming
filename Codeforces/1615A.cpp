#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;

	cin >> T;
	while (T--) {
		int n;

		cin >> n;
		int sum = 0;
		for (int i = 0, x; i < n; i++)
			cin >> x, sum += x;

		cout << (sum % n ? 1 : 0) << '\n';
	}
}
