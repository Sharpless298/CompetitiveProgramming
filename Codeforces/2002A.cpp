#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, m, k;
		cin >> n >> m >> k;

		cout << min(n, k) * min(m, k) << '\n';
	}
}
