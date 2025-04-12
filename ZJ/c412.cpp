#include <iostream>
using namespace std;

typedef long long int lli;

const int MOD = 1e9 + 7;

char c;
int T;
lli o, w, ans;

signed main() {
	cin >> T;

	while (T--) {
		o = w = ans = 0;

		while (true) {
			c = getchar_unlocked();

			if (c == 'O') {
				o++;
				ans += w;
				ans %= MOD;
			} else if (c == 'w') {
				w += o;
				w %= MOD;
			} else if (c == '\n')
				break;
		}

		cout << ans << '\n';
	}
}
