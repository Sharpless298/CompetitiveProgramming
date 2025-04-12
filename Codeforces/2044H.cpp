#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, q;
		cin >> n >> q;
		vector<vector<int>> a(n, vector<int>(n));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];

		vector<vector<long long>> pref(n + 1, vector<long long>(n + 1));
		vector<vector<long long>> pref_x(n + 1, vector<long long>(n + 1));
		vector<vector<long long>> pref_y(n + 1, vector<long long>(n + 1));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + a[i][j];
				pref_x[i + 1][j + 1] = pref_x[i + 1][j] + pref_x[i][j + 1] - pref_x[i][j] + a[i][j] * i;
				pref_y[i + 1][j + 1] = pref_y[i + 1][j] + pref_y[i][j + 1] - pref_y[i][j] + a[i][j] * j;
			}
		}

		for (int i = 0; i < q; i++) {
			int x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;

			x1--, y1--;
			int w = y2 - y1;

			long long sum1 = pref_x[x2][y2] - pref_x[x1][y2] - pref_x[x2][y1] + pref_x[x1][y1];
			long long sum2 = pref_y[x2][y2] - pref_y[x1][y2] - pref_y[x2][y1] + pref_y[x1][y1];
			long long sum3 = pref[x2][y2] - pref[x1][y2] - pref[x2][y1] + pref[x1][y1];
			cout << sum1 * w + sum2 + sum3 * (-x1 * w - y1 + 1) << " \n"[i == q - 1];
		}
	}
}
