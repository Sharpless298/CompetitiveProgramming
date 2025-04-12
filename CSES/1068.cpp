#include <iostream>
using namespace std;

typedef long long int lli;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	lli n;

	cin >> n;
	cout << n << ' ';
	while (n != 1) {
		if (n & 1)
			n = n * 3 + 1;
		else
			n /= 2;

		cout << n << ' ';
	}
	cout << '\n';
}
