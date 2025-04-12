#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, n, k, t;

	cin >> T;
	while (T--) {
		cin >> n >> k;

		t = n - k + 1;
		if (t > 0 && t & 1) {
			cout << "YES\n";
			for (int i = 0; i < k - 1; i++)
				cout << 1 << ' ';
			cout << t << '\n';
			continue;
		}
		t = n - 2 * (k - 1);
		if (t > 0 && !(t & 1)) {
			cout << "YES\n";
			for (int i = 0; i < k - 1; i++)
				cout << 2 << ' ';
			cout << t << '\n';
			continue;
		}

		cout << "NO\n";
	}
}
