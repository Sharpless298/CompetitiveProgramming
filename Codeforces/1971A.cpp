#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int x, y;
		cin >> x >> y;
		if (x > y)
			swap(x, y);

		cout << x << ' ' << y << '\n';
	}
}
