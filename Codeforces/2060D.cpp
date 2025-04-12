#include <bits/stdc++.h>
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
		for (int &i : a)
			cin >> i;

		for (int i = 0; i < n - 1; i++) {
			int t = min(a[i], a[i + 1]);
			a[i] -= t, a[i + 1] -= t;
		}
		vector<int> b = a;
		sort(b.begin(), b.end());
		cout << (b == a ? "YES\n" : "NO\n");
	}
}
