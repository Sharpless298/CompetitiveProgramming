#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<long long> pow(11);
	pow[0] = 1;
	for (int i = 0; i < 10; i++)
		pow[i + 1] = pow[i] * 10;
	int T;
	cin >> T;
	while (T--) {
		long long n;
		cin >> n;

		auto check = [](long long a) {
			while (a) {
				if (a % 10 == 7)
					return true;
				a /= 10;
			}
			return false;
		};
		int ans = 9;
		for (int i = 1; i <= 10; i++) {
			long long t = n;
			long long t2 = pow[i] - 1;

			for (int j = 0; j < 9; j++) {
				if (check(t))
					ans = min(ans, j);
				t += t2;
			}
		}
		cout << ans << '\n';
	}
}
