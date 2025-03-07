#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, x;
		long long k;
		cin >> n >> x >> k;
		string s;
		cin >> s;
		int t = 0x3f3f3f3f, p = (x == 0);
		for (int i = 0; i < n; i++) {
			if (s[i] == 'L')
				x--;
			else
				x++;

			if (x == 0) {
				t = i + 1;
				break;
			}
		}

		if (t == 0x3f3f3f3f || t > k) {
			cout << p << '\n';
			continue;
		}
		k -= t;
		x = 0;
		long long d = 0x3fffffffffffffff;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'L')
				x++;
			else
				x--;
			if (x == 0) {
				d = i + 1;
				break;
			}
		}
		cout << k / d + 1 + p << '\n';
	}
}
