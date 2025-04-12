#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;

	cin >> T;
	while (T--) {
		int n, x, y;

		cin >> n >> x >> y;
		x--, y--;
		vector<int> a(n, 1);

		int k = -1;
		for (int i = x + 1; i < n; i++)
			a[i] = k, k *= -1;
		k = -1;
		for (int i = y - 1; i >= 0; i--)
			a[i] = k, k *= -1;
		for (int i = 0; i < n; i++)
			cout << a[i] << " \n"[i + 1 == n];
	}
}
