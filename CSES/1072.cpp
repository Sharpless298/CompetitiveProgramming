#include <iostream>
using namespace std;

typedef long long int lli;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;
	for (int k = 1; k <= n; k++) {
		lli p = k * k, q = p * (p - 1) / 2;

		if (k > 2)
			q -= 4 * (k - 1) * (k - 2);
		cout << q << '\n';
	}
}
