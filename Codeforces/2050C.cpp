#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;

		int sum = 0, cnt2 = 0, cnt3 = 0;
		for (char c : s) {
			if (c == '2')
				cnt2++;
			if (c == '3')
				cnt3++;
			sum += c - '0';
		}
		sum %= 9;

		bool ok = false;
		for (int i = 0; i <= cnt2; i++) {
			for (int j = 0; j <= cnt3; j++) {
				if ((2 * i + 6 * j + sum) % 9 == 0) {
					ok = true;
					break;
				}
			}
			if (ok)
				break;
		}

		cout << (ok ? "YES\n" : "NO\n");
	}
}
