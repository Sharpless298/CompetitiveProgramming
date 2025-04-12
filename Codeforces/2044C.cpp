#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int m, a, b, c;
		cin >> m >> a >> b >> c;
		cout << min(m, a) + min(m, b) + min(m * 2 - min(m, a) - min(m, b), c) << '\n';
	}
}
