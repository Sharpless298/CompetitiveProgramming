#include <algorithm>
#include <iostream>
using namespace std;

int ary[64];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	bool f;
	int T, n;

	cin >> T;
	while (T--) {
		f = false;

		cin >> n;

		if (n >= 45) {
			cin.ignore();
			cin.ignore(1e9, '\n');
			cout << "YES\n";
			continue;
		}

		for (int i = 0; i < n; i++)
			cin >> ary[i];

		sort(ary, ary + n);
		for (int i = 0; i < n - 2; i++) {
			for (int j = i + 1; j < n - 1; j++) {
				for (int k = j + 1; k < n; k++) {
					if (ary[i] + ary[j] > ary[k]) {
						f = true;
						break;
					}
				}
			}
		}

		if (f)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
