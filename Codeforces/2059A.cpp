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
		set<int> a, b;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			a.insert(x);
		}
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			b.insert(x);
		}

		cout << (a.size() * b.size() >= 3 ? "YES\n" : "NO\n");
	}
}
