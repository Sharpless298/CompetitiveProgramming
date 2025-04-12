#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, p;

	cin >> n;

	for (int i = 2; i <= n; i++) {
		p = 0;
		while (n % i == 0) {
			p++;
			n /= i;
		}

		if (p >= 1) {
			if (p == 1)
				cout << i;
			else
				cout << i << '^' << p;

			if (n > 1)
				cout << " * ";
		}
	}

	cout << '\n';
}
