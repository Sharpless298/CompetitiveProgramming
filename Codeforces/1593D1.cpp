#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		int mn = 0x3f3f3f3f;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mn = min(mn, a[i]);
		}

		for (int i = 0; i < n; i++)
			a[i] -= mn;

		int ans = 0;
		for (int i = 0; i < n; i++)
			ans = __gcd(a[i], ans);

		cout << (ans == 0 ? -1 : ans) << '\n';
	}
}
