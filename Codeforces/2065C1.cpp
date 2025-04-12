#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(m);
		for (int &i : a)
			cin >> i;
		for (int &i : b)
			cin >> i;

		bool ok = true;
		a[0] = min(a[0], b[0] - a[0]);
		for (int i = 1; i < n; i++) {
			int p = a[i], q = b[0] - a[i];
			if (p > q)
				swap(p, q);
			if (p >= a[i - 1])
				a[i] = p;
			else if (q >= a[i - 1])
				a[i] = q;
			else {
				ok = false;
				break;
			}
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
}
