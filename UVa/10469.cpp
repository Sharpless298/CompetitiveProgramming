#include <iostream>
using namespace std;

typedef long long int lli;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	lli a, b;

	while (cin >> a >> b) {
		cout << (a ^ b) << '\n';
	}
}
