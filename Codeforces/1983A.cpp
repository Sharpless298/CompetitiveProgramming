#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, n;

	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cout << i << ' ';
		cout << '\n';
	}
}
