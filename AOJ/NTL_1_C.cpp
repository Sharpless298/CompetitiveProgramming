#include <iostream>
using namespace std;

int ary[16];

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, ans = 1;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> ary[i];

	for (int i = 0; i < n; i++)
		ans = lcm(ans, ary[i]);

	cout << ans << '\n';
}
