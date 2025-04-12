#include <iostream>
using namespace std;

typedef long long int lli;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		lli r;
		cin >> r;

		lli b = r, ans = 0;
		for (long long int i = 0; i <= r; i++) {
			while (i * i + b * b >= (r + 1) * (r + 1))
				b--;
			lli t = b;
			while (i * i + t * t >= r * r && t > 0)
				t--, ans++;
		}

		cout << ans * 4 << '\n';
	}
}
