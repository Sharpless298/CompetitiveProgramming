#include <bits/stdc++.h>
using namespace std;

vector<int> primes, lpf(10000001);
void sieve(int n) {
	fill(lpf.begin(), lpf.end(), 1);

	for (int i = 2; i <= n; i++) {
		if (lpf[i] == 1) {
			lpf[i] = i;
			primes.push_back(i);
		}
		for (int p : primes) {
			if (i * p > n) break;
			lpf[i * p] = p;
			if (p == lpf[i]) break;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	sieve(10000000);

	int T;
	cin >> T;
	while (T--) {
		int x, y;
		cin >> x >> y;

		if (x == y) {
			cout << 0 << '\n';
		} else if (y - x == 1) {
			cout << -1 << '\n';
		} else {
			int d = y - x, ans = 0x3f3f3f3f;
			while (lpf[d] != 1) {
				ans = min(ans, ((x - 1) / lpf[d] + 1) * lpf[d] - x);
				d /= lpf[d];
			}

			cout << ans << '\n';
		}
	}
}
