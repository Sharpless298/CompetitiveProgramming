#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
	return b ? gcd(b, a % b) : a;
}

long long gcd(long long a, long long b) {
	while (b) {
		a %= b;
		a ^= b, b ^= a, a ^= b;
	}
	return a;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << gcd(-2, -4) << '\n';
}
