#include <iostream>
using namespace std;

int t, n, T, w[1024], m[1024], dp[10005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;
	for (int i = 0, p, q, r; i < t; i++) {
		cin >> p >> q >> r;

		for (int j = 1; r >= j; r -= j, j <<= 1, n++)
			w[n] = p * j, m[n] = q * j;
		if (r)
			w[n] = p * r, m[n] = q * r, n++;
	}
	cin >> T;

	for (int i = 0; i < n; i++)
		for (int j = T; j >= w[i]; j--)
			dp[j] = max(dp[j - w[i]] + m[i], dp[j]);

	cout << dp[T] << '\n';
}
