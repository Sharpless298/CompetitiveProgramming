#include <iostream>
using namespace std;

int gcd(int a, int b) {
	return a ? gcd(b % a, a) : b;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b;

	cin >> a >> b;

	cout << gcd(a, b) << '\n';
}
