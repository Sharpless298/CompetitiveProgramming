#include <iostream>
using namespace std;

int a[1005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	bool f;
	int T, alice, bob, n, l, r, sum, k, moves;

	cin >> T;
	while (T--) {
		moves = alice = bob = 0;

		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];

		l = 0, r = n - 1, f = true, k = 0;
		while (l <= r) {
			sum = 0;

			if (f) {
				while (l <= r && sum <= k)
					sum += a[l++];
				alice += sum;
			} else {
				while (l <= r && sum <= k)
					sum += a[r--];
				bob += sum;
			}

			k = sum, moves++, f = !f;
		}

		cout << moves << ' ' << alice << ' ' << bob << '\n';
	}
}
