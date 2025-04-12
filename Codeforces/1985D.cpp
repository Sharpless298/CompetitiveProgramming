#include <iostream>
using namespace std;

int r[200005], c[200005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	char t;
	int T, n, m, mxr, mxc, ans_r, ans_c;

	cin >> T;
	while (T--) {
		mxr = mxc = -1;

		cin >> n >> m;

		for (int i = 0; i < n; i++)
			r[i] = 0;
		for (int i = 0; i < m; i++)
			c[i] = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> t;
				if (t == '#')
					r[i]++, c[j]++;

				if (r[i] > mxr)
					mxr = r[i], ans_r = i + 1;
				if (c[j] > mxc)
					mxc = c[j], ans_c = j + 1;
			}
		}

		cout << ans_r << ' ' << ans_c << '\n';
	}
}
