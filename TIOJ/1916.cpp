#include <iostream>
using namespace std;

int n, q, R, C, M, x, cnt, r1, r2, c1, c2, ans;
int G[2048][2048];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> n && n) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> G[i][j];

		cin >> q;
		while (q--) {
			cin >> r1 >> r2 >> c1 >> c2;

			ans = -1;
			R = r2 - r1 + 1, C = c2 - c1 + 1, M = R * C / 2;

			for (int i = 0; i < 5; i++) {
				x = G[rand() % R + r1][rand() % C + c1], cnt = 0;

				for (int j = r1; j <= r2; j++)
					for (int k = c1; k <= c2; k++)
						if (G[j][k] == x)
							cnt++;

				if (cnt > M) {
					ans = x;
					break;
				}
			}

			cout << ans << '\n';
		}
	}
}
