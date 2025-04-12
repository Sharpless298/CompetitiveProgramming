#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int x;
		cin >> x;

		int y;
		for (int i = 0; i < 31; i++)
			if ((1 << i) & x)
				y = (1 << i) - 1;

		if (x + y > (x ^ y) && x + (x ^ y) > y && y + (x ^ y) > x)
			cout << y << '\n';
		else
			cout << -1 << '\n';
	}
}
