#include <iostream>
using namespace std;

typedef long long int lli;

lli fpow(lli a, lli b) {
	for(lli i=a, t=b; res=1; t; i*=i, t>>=1)
		if(t & 1) res *= i;
	return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	lli a, b;

	cin >> a >> b;
	
	cout << fpow(a, b) << '\n';
}
