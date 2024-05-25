#include <iostream>
using namespace std;

typedef long long int lli;

lli fpow(lli a, lli b) {
	lli res = 1;

	while(b) {
		if(b & 1) res *= a;
		a *= a, b >>= 1;
	}

	return res;
}

signed main() {
	lli a, b;

	cin >> a >> b;

	cout << fpow(a, b) << '\n';
}
