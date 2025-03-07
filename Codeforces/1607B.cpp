#include <iostream>
using namespace std;

typedef long long int lli;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	lli x, n, t;

	cin >> T;
	while (T--) {
		cin >> x >> n;

		t = n % 4;
		if (t == 1)
			t = n;
		else if (t == 2)
			t = -1;
		else if (t == 3)
			t = -(n + 1);
		else
			t = 0;

		if (x & 1)
			x += t;
		else
			x -= t;

		cout << x << '\n';
	}
}
