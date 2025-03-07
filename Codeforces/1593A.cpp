#include <algorithm>
#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << max({b - a + 1, c - a + 1, 0}) << ' ' << max({a - b + 1, c - b + 1, 0}) << ' '
			 << max({a - c + 1, b - c + 1, 0}) << '\n';
	}
}
