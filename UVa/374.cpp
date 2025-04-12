#include <iostream>
using namespace std;

int m;

int fpow(int b, int p) {
	if (p == 0)
		return 1;
	if (p == 1)
		return b;

	int a = fpow(b, p / 2);

	if (p & 1)
		return (((a * a) % m) * b) % m;
	else
		return (a * a) % m;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int b, p;

	while (cin >> b >> p >> m) {
		cout << fpow(b % m, p) << '\n';
	}
}
