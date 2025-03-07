#include <iostream>
using namespace std;

int n, q;
int forest[1005][1005], pfs[1005][1005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			forest[i + 1][j + 1] = (c == '*');
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			pfs[i][j] = pfs[i - 1][j] + pfs[i][j - 1] - pfs[i - 1][j - 1] + forest[i][j];
		}
	}
	while (q--) {
		int y1, x1, y2, x2;

		cin >> y1 >> x1 >> y2 >> x2;

		cout << pfs[y2][x2] - pfs[y2][x1 - 1] - pfs[y1 - 1][x2] + pfs[y1 - 1][x1 - 1] << '\n';
	}
}
