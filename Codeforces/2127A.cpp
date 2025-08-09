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
		set<int> s;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x != -1) s.insert(x);
		}

		cout << ((s.count(0) || s.size() > 1) ? "NO\n" : "YES\n");
	}
}
