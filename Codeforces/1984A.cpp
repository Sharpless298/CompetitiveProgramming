#include <iostream>
using namespace std;

int a[55];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, n;

	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];

		if (a[0] == a[n - 1]) {
			cout << "NO\n";
			continue;
		} else {
			cout << "YES\n";
			string s(n, 'B');
			s[1] = 'R';
			cout << s << '\n';
		}
	}
}
