#include <iostream>
using namespace std;

bool f[128];
int n, k;

bool check(int x) {
	while (x) {
		if (f[x % 10])
			return false;
		x /= 10;
	}
	return true;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 0, x; i < k; i++)
		cin >> x, f[x] = true;

	while (!check(n))
		n++;

	cout << n << '\n';
}
