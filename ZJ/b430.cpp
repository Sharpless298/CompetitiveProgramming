#include <iostream>
using namespace std;

typedef long long int lli;

lli f(lli a, lli b, lli m) {
	lli res = 0;

	a %= m, b %= m;
	while (b) {
		if (b & 1)
			res = (res + a) % m;
		a = a * 2 % m, b >>= 1;
	}
	return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	lli a, b, n;

	while (cin >> a >> b >> n)
		cout << f(a, b, n) << '\n';
}
