#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, k, p;
		cin >> n >> k >> p;
		if (p * n < abs(k)) {
			cout << "-1\n";
			continue;
		}
		cout << abs(k) / p + (abs(k) % p != 0) << '\n';
	}
}
