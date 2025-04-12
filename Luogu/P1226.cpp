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
	lli a, b, p;

	cin >> a >> b >> p;

	cout << a << '^' << b << " mod " << p << '=' << fpow(a, b, p) << '\n';
}
