#include <iostream>
using namespace std;

typedef long long int lli;

lli fpow(lli a, lli b) {
	lli res = 1;

	for(lli i=a, t=b; t; i*=i, t>>=1)
		if(t & 1) res *= i;

	return res;
}

signed main() {
	lli a, b;

	cin >> a >> b;

	cout << fpow(a, b) << '\n';
}
