#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a[9];
	while (cin >> a[0]) {
		for (int i = 1; i < 9; i++)
			cin >> a[i];

		bool f = false;
		for (int i = 0; i < 9; i++) {
			if (!a[i])
				continue;

			if (f) {
				if (a[i] < 0)
					cout << " - ";
				else
					cout << " + ";

				if (i == 7) {
					if (abs(a[i]) != 1)
						cout << abs(a[i]);
					cout << "x";
				} else if (i == 8) {
					cout << abs(a[i]);
				} else {
					if (abs(a[i]) != 1)
						cout << abs(a[i]);
					cout << "x^" << 9 - i - 1;
				}
			} else {
				f = true;
				if (a[i] < 0)
					cout << "-";
				if (i == 7) {
					if (abs(a[i]) != 1)
						cout << abs(a[i]);
					cout << "x";
				} else if (i == 8) {
					cout << abs(a[i]);
				} else {
					if (abs(a[i]) != 1)
						cout << abs(a[i]);
					cout << "x^" << 9 - i - 1;
				}
			}
		}
		if (!f)
			cout << 0;

		cout << '\n';
	}
}
