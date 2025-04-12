#include <iostream>
using namespace std;

typedef long long int lli;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int Q, y, x;
	lli p, q;

	cin >> Q;
	while (Q--) {
		cin >> y >> x;

		p = max(x, y);
		q = p * p - p + 1;

		if (p & 1)
			cout << q + x - y << '\n';
		else
			cout << q + y - x << '\n';
	}
}
