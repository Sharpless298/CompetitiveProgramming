#include <iostream>
using namespace std;

int a[128][128][128], pref[128][128][128];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				cin >> a[i][j][k];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				pref[i][j][k] =
					pref[i - 1][j][k] + pref[i][j - 1][k] + pref[i][j][k - 1] + pref[i - 1][j - 1][k - 1] + a[i][j][k];
				pref[i][j][k] -= pref[i - 1][j - 1][k] + pref[i][j - 1][k - 1] + pref[i - 1][j][k - 1];
			}
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int lx, rx, ly, ry, lz, rz;
		cin >> lx >> rx >> ly >> ry >> lz >> rz;
		lx--, ly--, lz--;
		cout << pref[rx][ry][rz] - pref[lx][ry][rz] - pref[rx][ly][rz] - pref[rx][ry][lz] + pref[lx][ly][rz] +
					pref[lx][ry][lz] + pref[rx][ly][lz] - pref[lx][ly][lz]
			 << '\n';
		;
	}
}
