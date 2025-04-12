#include <iostream>
using namespace std;

typedef long long int lli;

int T, n;
int ary[200005];
lli l, r, tot, x;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> n >> x;
		for (int i = 0; i < n; i++)
			cin >> ary[i];

		l = 1, r = 2e9 + 5;
		while (l < r) {
			lli m = (l + r) >> 1;
			tot = 0;

			for (int i = 0; i < n; i++)
				tot += max(m - ary[i], 0LL);

			if (tot <= x)
				l = m + 1;
			else
				r = m;
		}

		cout << l - 1 << '\n';
	}
}
