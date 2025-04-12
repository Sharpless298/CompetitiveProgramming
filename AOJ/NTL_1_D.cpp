#include <iostream>
using namespace std;

int phi(int n) {
	int res = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			res -= res / i;
		}
	}
	if (n > 1)
		res -= res / n;

	return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;

	cout << phi(n) << '\n';
}
