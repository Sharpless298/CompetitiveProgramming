#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, x1, y1, x2, y2;

	cin >> T;
	while (T--) {
		cin >> x1 >> y1 >> x2 >> y2;

		if ((x1 < y1 && x2 < y2) || (x1 > y1 && x2 > y2))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
