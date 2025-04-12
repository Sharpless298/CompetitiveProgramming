#include <iostream>
using namespace std;

typedef long long int lli;

const lli MOD = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;

	cin >> T;
	while (T--) {
		lli a, b;

		cin >> a >> b;
		lli ans = 1;
		while (b) {
			if (b & 1)
				ans = ans * a % MOD;
			a = a * a % MOD, b >>= 1;
		}

		cout << ans << '\n';
	}
}
