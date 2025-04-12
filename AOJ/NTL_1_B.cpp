#include <iostream>
using namespace std;

typedef long long int lli;

const lli MOD = 1e9 + 7;

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

	int m, n;

	cin >> m >> n;
	cout << fpow(m, n) << '\n';
}
