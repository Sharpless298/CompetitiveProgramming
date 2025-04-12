#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, n0, n1, n2;
	string ans;

	cin >> T;
	while (T--) {
		ans.clear();

		cin >> n0 >> n1 >> n2;

		if (n1 == 0) {
			if (n0)
				for (int i = 0; i < n0 + 1; i++)
					cout << 0;
			else
				for (int i = 0; i < n2 + 1; i++)
					cout << 1;
			cout << '\n';
		} else {
			for (int i = 0; i < n1 + 1; i++) {
				if (i & 1)
					ans += '0';
				else
					ans += '1';
			}

			ans.insert(1, string(n0, '0'));
			ans.insert(0, string(n2, '1'));
			cout << ans << '\n';
		}
	}
}
