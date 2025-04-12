#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n;
	cin >> n;

	if (n <= 10) {
		cout << n - 1 << '\n';
		return 0;
	}
	n -= 10;
	if (n <= 9) {
		cout << n * 10 + n << '\n';
		return 0;
	}
	n -= 9;

	for (long long i = 90, k = 1;; i *= 10, k++) {
		for (int j = 0; j < 2; j++) {
			if (n <= i) {
				n--;
				long long temp = 1;
				for (int a = 0; a < k; a++)
					temp *= 10;

				n += temp;
				string ans = to_string(n);
				string t = ans.substr(0, ans.size() - (j == 0));
				reverse(t.begin(), t.end());
				ans = ans + t;
				cout << ans << '\n';

				return 0;
			}
			n -= i;
		}
	}
}
