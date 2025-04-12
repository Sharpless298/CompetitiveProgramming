#include <iostream>
using namespace std;

typedef long long int lli;

const long long int MOD = 1e9 + 7;

lli fpow(lli a, lli b) {
	lli res = 1;

	while (b) {
		if (b & 1)
			res = res * a % MOD;
		a = a * a % MOD, b >>= 1;
	}
	return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, l, r, k;

	cin >> T;
	while (T--) {
		cin >> l >> r >> k;

		if (k > 9) {
			cout << 0 << '\n';
			continue;
		}

		k = 9 / k + 1;

		cout << (fpow(k, r) - fpow(k, l) + MOD) % MOD << '\n';
	}
}
