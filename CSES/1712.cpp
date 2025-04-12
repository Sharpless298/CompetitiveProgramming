#include <iostream>
using namespace std;

typedef long long int lli;

const lli MOD = 1e9 + 7;

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

	int T;

	cin >> T;
	while (T--) {
		lli a, b, c;

		cin >> a >> b >> c;

		cout << fpow(a, fpow(b, c, MOD - 1), MOD) << '\n';
	}
}
