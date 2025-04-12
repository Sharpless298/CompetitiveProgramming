#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;

		if (k & 1) {
			for (int i = 0; i < n - 1; i++)
				cout << n << ' ';
			cout << n - 1 << '\n';
		} else {
			for (int i = 0; i < n - 2; i++)
				cout << n - 1 << ' ';
			cout << n << ' ' << n - 1 << '\n';
		}
	}
}
