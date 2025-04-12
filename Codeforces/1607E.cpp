#include <iostream>
using namespace std;

int T, n, m, x, y, mxx, mnx, mxy, mny;
string s;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		x = y = 0;
		mxx = mnx = 0;
		mxy = mny = 0;

		cin >> n >> m >> s;

		for (char c : s) {
			if (c == 'U')
				mny = min(mny, --y);
			else if (c == 'D')
				mxy = max(mxy, ++y);
			else if (c == 'R')
				mxx = max(mxx, ++x);
			else
				mnx = min(mnx, --x);

			if (mxx - mnx >= m) {
				if (x == mnx)
					mnx++;
				break;
			}
			if (mxy - mny >= n) {
				if (y == mny)
					mny++;
				break;
			}
		}

		cout << 1 - mny << ' ' << 1 - mnx << '\n';
	}
}
