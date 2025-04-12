#include <iostream>
using namespace std;

typedef long long int lli;

lli fpow(lli a, lli b, lli m) {
	lli res = 1;

	while (b) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m, b >>= 1;
	}
	return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	lli a, n, y, ans;

	while (cin >> a >> n >> y, a || n || y) {
		ans = 0;

		for (int i = 0; i < y; i++) {
			if (n == 0 && i == 0)
				continue;
			if (fpow(i, n, y) == a)
				ans++;
		}

		cout << ans << '\n';
	}
}
