#include <iostream>
using namespace std;

int gcd(int a, int b) {
	return b?gcd(b, a%b):a;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << gcd(-2, -4) << '\n';
}
