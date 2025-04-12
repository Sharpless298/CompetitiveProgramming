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
		sort(b.begin(), b.end());
		a[0] = min(a[0], b[0] - a[0]);
		bool ok = true;
		for (int i = 1; i < n; i++) {
			auto it = lower_bound(b.begin(), b.end(), a[i] + a[i - 1]);
			int p = a[i], q = (it == b.end() ? -0x3f3f3f3f : *it) - a[i];
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
