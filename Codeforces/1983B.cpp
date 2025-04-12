#include <cstring>
#include <iostream>
using namespace std;

int n, m;
char a[505][505], b[505][505];
int ra[505], rb[505], ca[505], cb[505];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;

	cin >> T;
	while (T--) {
		bool f = false;
		memset(ra, 0, sizeof(ra));
		memset(rb, 0, sizeof(rb));
		memset(ca, 0, sizeof(ca));
		memset(cb, 0, sizeof(cb));

		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> a[i][j];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> b[i][j];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ra[i] += a[i][j] - '0';
				rb[i] += b[i][j] - '0';
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				ca[i] += a[j][i] - '0';
				cb[i] += b[j][i] - '0';
			}
		}

		for (int i = 0; i < n; i++) {
			if ((ra[i] % 3) != (rb[i] % 3)) {
				f = true;
				break;
			}
		}
		for (int i = 0; i < m; i++) {
			if ((ca[i] % 3) != (cb[i] % 3)) {
				f = true;
				break;
			}
		}
		if (!f)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
