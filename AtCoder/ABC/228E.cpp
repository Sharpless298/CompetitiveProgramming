#include <iostream>
using namespace std;

typedef long long int lli;

const int MOD = 998244353;

lli fpow(lli a, lli b, lli mod) {
	lli res = 1;
	a %= mod;
	while (b) {
		if (b & 1)
			res = res * a % mod;
		a = a * a % mod, b >>= 1;
	}

	return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long int n, k, m;
	cin >> n >> k >> m;

	cout << (m % MOD ? fpow(m, fpow(k, n, MOD - 1), MOD) : 0) << '\n';
}
