#include <cstring>
#include <iostream>

using namespace std;

bool m[105][105];
int r[105], c[105];
int r_odd, c_odd;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	while (cin >> n && n) {
		memset(r, 0, 420);
		memset(c, 0, 420);
		r_odd = 0, c_odd = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> m[i][j];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				r[i] += m[i][j];
				c[j] += m[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			if (r[i] & 1)
				r_odd++;
			if (c[i] & 1)
				c_odd++;
		}

		if (r_odd == 0 && c_odd == 0)
			cout << "OK\n";
		else if (r_odd == 1 && c_odd == 1) {
			cout << "Change bit (";
			for (int i = 0; i < n; i++) {
				if (r[i] & 1) {
					cout << i + 1;
					break;
				}
			}
			cout << ',';
			for (int i = 0; i < n; i++) {
				if (c[i] & 1) {
					cout << i + 1;
					break;
				}
			}
			cout << ")\n";
		} else
			cout << "Corrupt\n";
	}
}
